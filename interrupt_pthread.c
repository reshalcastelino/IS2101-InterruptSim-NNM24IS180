#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

int mask_keyboard = 0;
int mask_mouse = 0;
int mask_printer = 1;
pthread_mutex_t lock;

void log_interrupt(const char *msg) {
    pthread_mutex_lock(&lock);
    FILE *f = fopen("interrupt_log.txt", "a");
    if (f) {
        time_t now = time(NULL);
        struct tm *t = localtime(&now);
        fprintf(f, "[%02d:%02d:%02d] %s\n", t->tm_hour, t->tm_min, t->tm_sec, msg);
        fclose(f);
    }
    pthread_mutex_unlock(&lock);
}

void *handle_interrupt(void *arg) {
    char *device = (char *)arg;
    char msg[200];
    sprintf(msg, "%s Interrupt Triggered -> Handling ISR -> Completed", device);
    printf("%s\n", msg);
    log_interrupt(msg);
    sleep(1);
    return NULL;
}

int main() {
    srand(time(0));
    pthread_t t;
    pthread_mutex_init(&lock, NULL);

    printf("=== INTERRUPT HANDLING SIMULATION (pthreads) ===\n");
    printf("Priority: Keyboard > Mouse > Printer\n");
    printf("Masking Status: Keyboard=0, Mouse=0, Printer=1\n\n");

    for (int i = 0; i < 6; i++) {
        int dev = rand() % 3;
        if (dev == 0 && !mask_keyboard)
            pthread_create(&t, NULL, handle_interrupt, "Keyboard");
        else if (dev == 1 && !mask_mouse)
            pthread_create(&t, NULL, handle_interrupt, "Mouse");
        else if (dev == 2 && !mask_printer)
            pthread_create(&t, NULL, handle_interrupt, "Printer");
        else {
            printf("Interrupt Ignored (Masked)\n");
            log_interrupt("Interrupt Ignored (Masked)");
        }
        pthread_join(t, NULL);
        sleep(1);
    }

    pthread_mutex_destroy(&lock);
    printf("\nExecution stopped. All interrupts handled successfully.\n");
    return 0;
}
