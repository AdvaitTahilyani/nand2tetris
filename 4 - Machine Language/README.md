# Project 4: Machine Language

## Overview

In Project 4 of the Nand2Tetris course, I explored the fundamentals of assembly language by developing programs directly targeting the Hack computer's hardware. This project involved writing low-level code to manipulate memory and handle input/output operations, solidifying my understanding of how software interfaces with hardware.

## Programs Implemented

### Screen Fill (`Fill.asm`)
- **Functionality**: This program runs an infinite loop that monitors keyboard input. Upon detecting any key press, it blackens the screen by writing "black" in every pixel. When no key is pressed, the screen is cleared.
- **Key Components**:
  - **Infinite Loop**: Continuously checks for keyboard input.
  - **I/O Handling**: Directly interacts with the memory-mapped I/O to detect key presses and modify screen pixels.
  - **Conditionals**: Implements checks to determine the state of the keyboard and update the screen accordingly.

### Multiplication (`Mult.asm`)
- **Functionality**: Multiplies the values in RAM[0] (R0) and RAM[1] (R1) and stores the result in RAM[2] (R2). The multiplication is implemented using repetitive addition based on the values of R0 and R1.
- **Key Components**:
  - **Repetitive Addition**: Uses a loop to add R1 to itself R0 times.
  - **Control Flow**: Manages loop execution and checks conditions to ensure correct computation.
  - **Memory Access**: Directly reads from and writes to specific RAM addresses to retrieve operands and store results.

### How to Run the Implementation

To run and test the implementations of these programs use the CPU Emulator at https://nand2tetris.github.io/web-ide/cpu

## Conclusion

Project 4 provided a hands-on approach to assembly language programming, bridging the gap between high-level programming concepts and low-level machine operations. These assembly programs demonstrate essential techniques such as looping, condition checking, direct memory access, and input/output handling, which are crucial for developing more complex software that interacts with computer hardware.
