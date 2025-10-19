 IS2101-InterruptSimPthread-NNM24IS180
 Interrupt Handling Simulation (pthreads)

Name:Reshal Melissa Castelino  
Usn:NNM24IS180  
Language:C 

Description
This project simulates interrupt handling using pthreads in C.  
Three I/O devices — Keyboard, Mouse, and Printer — generate interrupts that are handled based on priority.  
The user can also mask or unmask devices while the program runs.

How to Compile & Run
```bash
gcc interrupt_pthread.c -o interrupt_pthread -lpthread
interrupt_pthread
