# Project 8: VM II: Program Control

## Overview

In Project 8 of the Nand2Tetris course, I extended the capabilities of the virtual machine translator developed in Project 7 to include support for program control commands using C++. This involved translating VM commands related to program flow—like labels, conditional and unconditional jumps, and function calling/returning—into Hack assembly language.

## Implementation Highlights

### Translator Enhancements
- **Program Control**: Implements the translation of VM commands for controlling the flow of the program, such as `label`, `goto`, `if-goto`, `function`, `call`, and `return`.
- **Function Management**: Manages function declarations and returns, including setting up local environments and handling return addresses.

### Key Components
- **Parser**: Extended to recognize and handle new VM commands related to program control. It extracts necessary details from each command to facilitate correct assembly translation.
- **Code Writer**: Augmented to generate Hack assembly code that implements complex control structures and function calls.
  - **Label Commands**: Translates VM `label` commands into assembly labels.
  - **Goto Commands**: Handles both conditional and unconditional jumps within the Hack assembly output.
  - **Function Commands**: Manages the assembly code generation for function declaration, including setting up a stack frame.
  - **Call and Return Commands**: Implements the translation of function calls and returns, ensuring proper stack management and program execution continuation.

### Usage
To use the updated VM translator:
1. Compile the C++ code using the included makefile command.
2. Run the executable with a `.vm` file as an argument.
3. The translator outputs a `.asm` file with the assembly code capable of executing the given VM code, including advanced program control structures.

## Conclusion
Project 8 builds on the virtual machine translation process by incorporating elements of program control, allowing for the translation of VM code that includes complex flow control and function management. This project not only enhances the understanding of how high-level control structures are implemented at the machine level but also showcases the integration of function calls and returns in a virtual machine context.
