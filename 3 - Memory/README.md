# Project 3: Building Memory Chips

## Overview

In Project 3 of the Nand2Tetris course, I expanded my focus to include memory components, crucial for data storage in computing systems. By integrating the D Flip-Flop (DFF) and leveraging the gates constructed in earlier projects, I designed and implemented various types of memory chips.

## Chips Implemented

### Bit
- **Functionality**: Stores a single bit of information, either 0 or 1.
- **Components Used**: Based on the D Flip-Flop (DFF) with logic to control whether the bit should hold its value or update to a new value using a MUX (multiplexer) gate.

### Register
- **Functionality**: Holds a 16-bit word, enabling storage and retrieval of multi-bit values.
- **Components Used**: Comprised of 16 Bit components, one for each bit in the word, combined to function as a single 16-bit register.

### Program Counter (PC)
- **Functionality**: Specialized register that keeps track of the address of the machine instruction currently being executed, and updates itself to point to the next instruction.
- **Components Used**: Incorporates a register, an incrementer to advance the count, and logic to handle reset, load, and increment operations.

### RAM (Random Access Memory)
- **Sizes Implemented**: RAM8, RAM64, RAM512, RAM4K, and RAM16K
- **Functionality**: Provides read and write access to a series of memory locations.
- **Components Used**: Each RAM chip is recursively built from smaller RAM units (e.g., RAM8 built from 8 Registers, RAM64 from 8 RAM8 units, etc.), incorporating decoders to direct read/write operations to the correct memory location.

## Conclusion

The third project not only reinforced my understanding of sequential logic but also allowed me to explore the hierarchical construction of memory systems in digital computers. From single bits to comprehensive memory arrays, these implementations demonstrate the layered approach to building complex memory architectures in modern computing.
