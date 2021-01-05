; set B
MVI B, 00H
; set A
LDA 1H
MOV C, A
LDA 0H
MOV D, A
MVI A, 00H
; recurse
REPEAT: ADD D
JNC FWD 
INR B
FWD: DCR C
JNZ REPEAT
STA 2H
; move to A
MOV A, B
; store to memory
STA 3H
HLT