// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/4/Fill.asm

// Runs an infinite loop that listens to the keyboard input. 
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel. When no key is pressed, 
// the screen should be cleared.

(LOOP)
    @KBD
    D=M
    @NEX
    D;JEQ
    D=-1
    @SKIP
    0;JMP
(NEX)
    D=0
(SKIP)
    @n
    M=0
    @v
    M=D
(ITER)
    @8192
    D=A
    @n
    D=D-M
    @END
    D;JEQ
    @SCREEN
    D=A
    @n
    D=D+M
    @R0
    M=D
    @v
    D=M
    @R0
    A=M
    M=D
    @n
    M=M+1
    @ITER
    0;JMP
(END)
    @LOOP
    0;JMP
