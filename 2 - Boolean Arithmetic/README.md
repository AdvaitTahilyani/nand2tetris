# Project 2: Boolean Arithmetic

## Overview

In the second project of the Nand2Tetris course, I leveraged the basic logical gates created in Project 1 to build more complex arithmetic chips. These chips form the building blocks of the arithmetic logic unit (ALU) that are crucial in computer architecture.

## Chips Implemented

### Half Adder
- **Functionality**: Calculates the sum and carry values for a single bit addition.
- **Components Used**: Utilizes an XOR gate for the sum and an AND gate for the carry.

### Full Adder
- **Functionality**: Performs addition of two bits, taking into account a carry input from a previous addition.
- **Components Used**: Integrates two Half Adders and an OR gate to produce the sum and carry out.

### 16-bit Adder
- **Functionality**: Extends the Full Adder logic to handle 16-bit integers.
- **Components Used**: Uses 16 Full Adders chained together, where the carry output of one adder is the carry input of the next.

### Arithmetic Logic Unit (ALU)
- **Functionality**: A fundamental computing unit capable of performing various arithmetic and logical operations.
- **Components Used**: Built upon all the previous chips, including logic gates from Project 1 and adders from Project 2. Capable of operations like addition, subtraction, negation, and bitwise operations such as AND, OR, and NOT.
  
### How to Run the Implementation

To run and test the implementations of these logical chips use the hardware simulator at https://nand2tetris.github.io/web-ide/chip/

## Conclusion

The second project effectively demonstrates how simple logical gates can be utilized to construct essential arithmetic functions within a computer system. By building from the ground up, starting with NAND gates, and advancing to a complete ALU, this project provides a hands-on approach to understanding the core components of digital computing systems.
