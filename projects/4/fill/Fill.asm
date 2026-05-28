// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/4/Fill.asm

// Runs an infinite loop that listens to the keyboard input. 
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel. When no key is pressed, 
// the screen should be cleared.

//// Replace this comment with your code.

(LOOP)
@KBD
D=M

@WHITE_LOOP
D;JEQ
@BLACK_LOOP
0;JMP

(WHITE_LOOP)
@SCREEN
D=A
@address
M=D
@i
M=0

(WHITE_INNER_LOOP)
@i
D=M
@8192
D=D-A
@LOOP
D;JEQ

@address
A=M
M=0

@address
M=M+1
@i
M=M+1

@WHITE_INNER_LOOP
0;JMP

(BLACK_LOOP)
@SCREEN
D=A
@address
M=D
@i
M=0

(BLACK_INNER_LOOP)
@i
D=M
@8192
D=D-A
@LOOP
D;JEQ

@address
A=M
M=-1

@address
M=M+1
@i
M=M+1

@BLACK_INNER_LOOP
0;JMP