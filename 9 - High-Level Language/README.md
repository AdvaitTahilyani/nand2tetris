# Project 9: High-Level Language - Jack

## Overview

In Project 9 of the Nand2Tetris course, I delved into the world of high-level programming by designing and implementing a primitive version of the classic Snake game using the Jack programming language. This project served as a practical introduction to Jack, a simple object-oriented programming language developed specifically for educational purposes within the Nand2Tetris curriculum.

## Game Implementation

### Features of the Snake Game
- **Gameplay**: The player controls a snake that moves around the screen, eating food to grow longer. Each piece of food the snake eats increases its length and the game's score.
- **Controls**: The snake is controlled using keyboard inputs that dictate its movement direction.
- **End Game Condition**: The game ends if the snake runs into itself or the edge of the screen.

### Jack Language Features Used
- **Classes and Objects**: Utilized object-oriented principles to manage game elements such as the snake, game board, and food items.
- **Control Structures**: Implemented loops and conditional statements to handle game logic and user inputs.
- **Array Manipulation**: Used arrays to track the positions of the snake's segments on the grid.
- **Screen Drawing**: Interacted with the Jack OS API to draw and update the graphical representation of the game board and snake.

### Key Components
- **Snake Class**: Manages the attributes and behavior of the snake, including its growth and movement.
- **GameBoard Class**: Handles the display of the snake and food, as well as the detection of collisions.
- **Main Program**: Sets up the game environment and manages the game loop, user inputs, and updates to the game state.

## Usage
To play the Snake game:
1. Compile the Jack code using the Jack compiler.
2. Run the compiled VM code on the Hack platform.
3. Use the keyboard controls to play the game.

## Conclusion
Project 9 provided a hands-on experience with the Jack language, demonstrating its capabilities in managing object-oriented concepts and interactive applications. By building the Snake game, I gained a deeper understanding of programming constructs and system interactions at a higher level of abstraction. This project showcases the potential of educational programming languages in creating engaging and instructive software projects.
