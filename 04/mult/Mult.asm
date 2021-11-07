// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)
//
// This program only needs to handle arguments that satisfy
// R0 >= 0, R1 >= 0, and R0*R1 < 32768.

@1
D=M
@first
M=D

@0
D=A
@result
M=D
(LOOP)
@first
D=M
@FINISH
D;JLE
D=D-1
@first
M=D
@result
D=M
@0
D=D+M
@result
M=D
@LOOP
0;JMP
(FINISH)

@result
D=M
@2