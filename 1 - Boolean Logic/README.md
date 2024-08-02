# Project 1: Building Logical Chips from NAND

## Overview

In this project, I embarked on constructing basic logical gates using only NAND gates, as part of the initial phase of the Nand2Tetris course. The NAND gate is a universal gate, meaning it can be used to create any other standard gate. This approach demonstrates the fundamental versatility and power of the NAND gate in digital logic design.

## Implementation

### Logical Chips Created

Here are the logical chips that I developed using solely the NAND gate:

- **NOT Gate**
  - Implements a simple logical NOT operation using a single NAND gate by connecting both inputs of the NAND to the same input signal.
- **AND Gate**
  - Constructs an AND gate using three NAND gates. The logic follows that the output of an AND gate is the negation of NAND's output when both inputs are the same.
- **OR Gate**
  - Designed using three NAND gates. This configuration exploits the fact that the OR operation can be represented as a combination of NAND operations on inverted inputs.
- **XOR Gate**
  - More complex, the XOR gate is realized by arranging four NAND gates. It is based on the principle that XOR can be expressed in terms of AND, OR, and NOT operations, which in turn are built using NANDs.

Each of these chips is implemented in a separate `.hdl` file where the internal architecture is defined based on the NAND logic.

### How to Run the Implementation

To run and test the implementations of these logical chips:

1. **Setup your environment:**

   - Ensure that the Nand2Tetris software suite is installed on your machine. This includes the Hardware Simulator which is necessary for testing the chip designs.

2. **Load the chip:**

   - Open the Hardware Simulator, navigate to the project directory, and load the `.hdl` file corresponding to the chip you wish to test (e.g., `And.hdl`).

3. **Run the tests:**

   - Load the corresponding test script (e.g., `And.tst`) in the simulator and run it. The simulator will execute the test script against your chip implementation and provide instant feedback.

4. **Evaluate results:**
   - Check the output from the simulator to verify that your chip behaves as expected according to the logic of the gate being simulated.

By following these steps, you can test each logical gate implemented using NAND gates and understand the underlying logic and structure.

## Conclusion

This project highlights the foundational role of NAND gates in digital electronics, illustrating how complex operations can be broken down into simpler, universal operations. By using just the NAND gate, we are able to construct all the essential building blocks of digital logic.
