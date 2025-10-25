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
```
Output
<img width="849" height="681" alt="Screenshot 2025-10-19 213928" src="https://github.com/user-attachments/assets/def52d18-974d-4613-8ec9-89b5b8bc7ac9" />

<img width="932" height="674" alt="Screenshot 2025-10-19 214001" src="https://github.com/user-attachments/assets/c0555a5a-0556-482f-a6a8-5d5531742230" />

<img width="836" height="453" alt="Screenshot 2025-10-19 214015" src="https://github.com/user-attachments/assets/576e6785-d39d-4526-ad51-c272aee51ed0" />

Concusion
This program demonstrates how interrupts from multiple devices are handled based on priority using pthreads.
It also shows how masking can be used to temporarily disable certain interrupts, giving a simple yet clear view
of how real-time interrupt handling works in operating systems.
