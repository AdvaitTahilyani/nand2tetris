# Project 6: Assembler

## Overview

In Project 6 of the Nand2Tetris course, I developed an assembler in C++ that translates Hack assembly language into binary machine code understandable by the Hack hardware platform. This project bridges the gap between high-level programming and machine-level execution, providing an essential tool for running custom programs on the Hack computer.

## Implementation Highlights

### Assembler Workflow
- **Parsing**: Reads and parses assembly instructions from a `.asm` file, handling white space and comments for clean input processing.
- **Code Translation**: Converts each assembly command into its binary equivalent. This involves:
  - **A-instructions**: Resolving symbols and numbers into binary addresses.
  - **C-instructions**: Breaking down each instruction into its constituent parts (`dest`, `comp`, `jump`) and converting them into binary codes.

### Key Components
- **Symbol Table**: Manages predefined symbols, labels, and variable addresses. This component is critical for symbol resolution during the first and second passes of the assembly process.
- **Code Module**: Translates mnemonics to binary codes, ensuring that each part of the C-instruction is accurately represented in machine language.
- **I/O Management**: Handles file reading and writing operations, enabling the assembler to process input files and output the corresponding binary code.

### Two-Pass Assembly Process
- **First Pass**: Scans through the assembly code to record label definitions into the symbol table without generating any machine code.
- **Second Pass**: Processes each line again, this time translating it into binary code using the symbol table filled in the first pass for symbol resolution.

## Usage
To use the assembler:
1. Compile the C++ code using the included makefile.
2. Run the executable with an `.asm` file as an argument.
3. The assembler outputs a `.hack` file containing the binary code.

## Conclusion
This assembler project not only reinforces concepts of assembly language but also demonstrates the practical application of compilers that translate human-readable code into a format executable by computers. By building this tool in C++, I gained a deeper understanding of both software development and computer architecture.

