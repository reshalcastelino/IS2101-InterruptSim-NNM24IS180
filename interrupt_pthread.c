#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int mask_keyboard = 0, mask_mouse = 0, mask_printer = 0;

void* keyboard_isr(void* arg) {
    if (!mask_keyboard)
        printf("Keyboard Interrupt Triggered -> Handling ISR -> Completed\n");
    else
        printf("Keyboard Interrupt Masked\n");
    return NULL;
}

void* mouse_isr(void* arg) {
    if (!mask_mouse)
        printf("Mouse Interrupt Triggered -> Handling ISR -> Completed\n");
    else
        printf("Mouse Interrupt Masked\n");
    return NULL;
}

void* printer_isr(void* arg) {
    if (!mask_printer)
        printf("Printer Interrupt Triggered -> Handling ISR -> Completed\n");
    else
        printf("Printer Interrupt Masked\n");
    return NULL;
}

int main() {
    int choice, device;
    pthread_t t1, t2, t3;

    while (1) {
        printf("\n=== Interrupt Handling Simulation (pthreads) ===\n");
        printf("1. Trigger Keyboard Interrupt\n");
        printf("2. Trigger Mouse Interrupt\n");
        printf("3. Trigger Printer Interrupt\n");
        printf("4. Mask/Unmask Devices\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                pthread_create(&t1, NULL, keyboard_isr, NULL);
                pthread_join(t1, NULL);
                break;
            case 2:
                pthread_create(&t2, NULL, mouse_isr, NULL);
                pthread_join(t2, NULL);
                break;
            case 3:
                pthread_create(&t3, NULL, printer_isr, NULL);
                pthread_join(t3, NULL);
                break;
            case 4:
                printf("Select device: 1.Keyboard 2.Mouse 3.Printer\n");
                scanf("%d", &device);
                if (device == 1)
                    mask_keyboard = !mask_keyboard;
                else if (device == 2)
                    mask_mouse = !mask_mouse;
                else if (device == 3)
                    mask_printer = !mask_printer;
                printf("Mask toggled successfully!\n");
                break;
            case 5:
                printf("Exiting simulation\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}