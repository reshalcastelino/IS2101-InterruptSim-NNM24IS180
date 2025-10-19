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

Output

<img width="849" height="681" alt="Screenshot 2025-10-19 213928" src="https://github.com/user-attachments/assets/8c51ab66-058f-458f-9415-fac10a146fdb" />
<img width="932" height="674" alt="Screenshot 2025-10-19 214001" src="https://github.com/user-attachments/assets/8c686898-2771-488c-ab8e-2cc6c2ef13fb" />
<img width="836" height="453" alt="Screenshot 2025-10-19 214015" src="https://github.com/user-attachments/assets/8f5713d0-0c19-4762-b8dc-bfaeda9f0a3d" />

Conclusion
This program demonstrates how interrupts from multiple devices are handled based on priority using pthreads.
It also shows how masking can be used to temporarily disable certain interrupts, giving a simple yet clear view
of how real-time interrupt handling works in operating systems.
