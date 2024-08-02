# Project 7: VM I: Stack Arithmetic

## Overview

In Project 7 of the Nand2Tetris course, I developed a virtual machine (VM) translator in C++ that converts VM commands, specifically those related to stack arithmetic and memory access, into Hack assembly language. This translator facilitates the execution of higher-level operations on the Hack platform, providing an abstraction layer above the hardware.

## Implementation Highlights

### Translator Components
- **Parser**: Analyzes VM commands and extracts key components such as command types, arguments, and operational details. Handles commands for arithmetic operations and memory access (push and pop).
- **Code Writer**: Translates parsed VM commands into Hack assembly instructions. Outputs the resulting assembly code to a `.asm` file.

### Supported VM Commands
- **Arithmetic Commands**: Handles basic arithmetic operations like `add`, `sub`, `neg`, `eq`, `gt`, `lt`, `and`, `or`, and `not`. These commands are translated into corresponding assembly sequences that manipulate the stack to perform the desired operations.
- **Memory Access Commands**: Implements `push` and `pop` operations for different memory segments including `constant`, `local`, `argument`, `this`, `that`, `temp`, and `pointer`.

### Functional Workflow
1. **Initialization**: The translator starts by setting up necessary assembly codes for stack initialization and memory segment base addresses.
2. **Parsing**: Each line of VM code is read and analyzed to determine the type of command and its parameters.
3. **Code Generation**: For each command, appropriate assembly code is generated. This includes:
   - **Stack Arithmetic**: Generating assembly instructions that perform arithmetic and logical operations using the stack.
   - **Memory Access**: Translating VM memory commands into assembly code that accesses and manipulates specific memory addresses.

### Usage
To use the VM translator:
1. Compile the C++ code using the provided makefile.
2. Run the executable with a `.vm` file as an argument to produce an `.asm` file containing the translated assembly code.

## Conclusion
Project 7 introduces the foundational components of virtual machine translation, illustrating how high-level VM commands are systematically translated into low-level assembly instructions. This project is essential for understanding the workings of a virtual machine that supports complex programming constructs and operations in the Hack computing platform.
