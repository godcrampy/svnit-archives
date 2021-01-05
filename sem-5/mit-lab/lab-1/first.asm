; 1. Store 8 bit data in memory
; store 0x25 in B
MVI B, 25H
; store address of 0x0001 to HL
LXI H, 0001H
; move data in B to M
MOV M, B

; 2. Exchange contents of memory
MVI C, 45H
LXI H, 0004H
; 0x0004 has 45
MOV M, C
;XCHG

LHLD 0001H
XCHG
LHLD 0004H
SHLD 0001H
XCHG
SHLD 0004H

; 3. Add 2 8 bit numbers
; clear accumulator
LDA 0000H
; B = 0x12
MVI B, 12H
; C = 0x10
MVI C, 10H
; A = B
ADD B
; A = B + C
ADD C

; 4. Subtract 2 8 bit numbers
; clear accumulator
LDA 0000H
ADD B
SUB C

; 5. Add 2 16 bit numbers
; first number
LXI B, 1001H
; second number
LXI D, 0112H
; clear HL
LXI H, 0000H
; Add numbers
DAD B
DAD D

; 6. Add contents of memory locations
; load contents of 0x0001 to A
LDA 0001H
; load 0x0020 to 0x0002
MVI C, 20H
LXI H, 0002H
MOV M, B
; add to accumulator
ADD M

; 7. Subtract 2 16 bit numbers
; first number
LXI H, 1001H
; move to de
XCHG
; second byte
LXI H, 1000H
; first byte
MOV A, E
SUB L
MOV L, A
; second byte
MOV A, D
SBB H
MOV H, A
SHLD 0003H

HLT