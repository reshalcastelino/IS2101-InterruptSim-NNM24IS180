 IS2101-InterruptSimPthread-NNM24IS180
 Interrupt Handling Simulation (pthreads)

Name:Reshal Melissa Castelino  
Usn:NNM24IS180  
Language:C 

## Description
This program simulates interrupt handling from multiple I/O devices (Keyboard, Mouse, Printer) using pthreads in C.  
Each device has a fixed priority:
- Keyboard → High priority  
- Mouse → Medium priority  
- Printer → Low priority  
The program automatically triggers interrupts and ensures that higher priority interrupts are handled first.  
It also supports masking, where masked devices are ignored during execution.  
After execution, a message is displayed that all interrupts have been handled successfully.

## Inputs and Outputs
Inputs:  
Nomanual input is required. The program randomly generates interrupts for Keyboard, Mouse, and Printer.  
Outputs:
The program prints interrupt handling status messages on the terminal, such as:  
- `Keyboard Interrupt Triggered -> Handling ISR -> Completed`  
- `Interrupt Ignored (Masked)`  
- `Execution stopped. All interrupts handled successfully.`  

## How to Compile & Run
```bash
gcc interrupt_s
imulation.c -o interrupt_simulation -lpthread
interrupt_simulation
```
## Sample Output
=== INTERRUPT HANDLING SIMULATION (pthreads) ===
Priority: Keyboard > Mouse > Printer
Masking Status: Keyboard=0, Mouse=0, Printer=1

Keyboard Interrupt Triggered -> Handling ISR -> Completed
Mouse Interrupt Triggered -> Handling ISR -> Completed
Interrupt Ignored (Masked)
Keyboard Interrupt Triggered -> Handling ISR -> Completed
Mouse Interrupt Triggered -> Handling ISR -> Completed
Interrupt Ignored (Masked)

Execution stopped. All interrupts handled successfully.

## Output

<img width="855" height="338" alt="Screenshot 2025-10-27 181526" src="https://github.com/user-attachments/assets/52d3ecb4-f882-49fe-8e15-0f680185d081" />

