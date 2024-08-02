# Project 5: Computer Architecture

## Overview

In Project 5 of the Nand2Tetris course, I focused on constructing the central components of a computer system, namely the CPU, Memory, and the complete Computer architecture. This involved using Hardware Description Language (HDL) and integrating previously developed components like ALU, Registers, and RAM units to build a functional computer model.

## Components Implemented

### CPU (Central Processing Unit)
- **Functionality**: The CPU serves as the brain of the computer, responsible for executing instructions, performing calculations, and managing data flow between memory and compute resources.
- **Key Components**:
  - **ALU**: Utilizes the Arithmetic Logic Unit from Project 2 for all arithmetic and logic operations.
  - **Registers**: Implements multiple registers to hold the current instruction, address, and data values.
  - **Control Logic**: Determines the sequence of operations including fetching, decoding, and executing instructions.

### Memory
- **Functionality**: Combines both the Data Memory (RAM) and Instruction Memory (ROM) to provide storage for both the program instructions and the runtime data.
- **Key Components**:
  - **RAM**: Built from the scalable RAM units designed in Project 3, this memory is used for storing and retrieving data dynamically during execution.
  - **ROM**: Holds the computer’s program code, loaded from a predefined file containing the machine instructions.

### Computer
- **Functionality**: Integrates the CPU and Memory with input/output management to create a fully operational computer system.
- **Key Components**:
  - **CPU and Memory Integration**: Connects the CPU to both the RAM and ROM, enabling the CPU to execute stored programs and manipulate data.
  - **I/O Interface**: Interfaces with external devices, handling input and output operations through memory-mapped I/O.

### How to Run the Implementation

To run and test the implementations of these individual parts use the hardware simulator at https://nand2tetris.github.io/web-ide/chip/. To see the computer in action, the three included scripts can be executed using the CPU emulator at https://nand2tetris.github.io/web-ide/cpu/.

## Conclusion

Project 5 encapsulates the culmination of the preceding projects into a singular coherent structure, demonstrating the functional synergy between individual hardware components in a computer system. By building the CPU, Memory, and integrating these with I/O handling to form the Computer, this project provided a deep dive into the intricacies of computer architecture, showcasing the practical application of theoretical concepts in digital system design.
