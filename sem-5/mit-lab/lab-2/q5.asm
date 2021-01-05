; set memory location
LXI H, 0001H
; first number
MOV A, M
INX H
; second number
MOV B, M
CMP B
; if carry is set A is less else B is less
JNC 420BH
MOV A, B
INX H
; Move answer to 0x0003
MOV M, A
HLT
