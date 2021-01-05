; initialize data in C
MVI C, 10H
; move to A
MOV A, C
; shift
RRC
RRC
RRC
RRC
; move back to C
MOV C, A
HLT