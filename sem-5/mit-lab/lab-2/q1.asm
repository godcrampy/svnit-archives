; initialize data in C
MVI C, 01H
; move to A
MOV A, C
; shift
RLC
RLC
RLC
; move back to C
MOV C, A
HLT