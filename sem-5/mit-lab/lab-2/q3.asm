; clear accumulator
MVI A, 00H
; set memory location
LXI H, 0001H
; FIRST NUMBER
; move data to c
MOV C, M
ADD C
; increase memory by one
INX H

; SECOND NUMBER
MOV C, M
ADD C
; increase memory by one
INX H

; THIRD NUMBER
MOV C, M
ADD C
; increase memory by one
INX H

; FOURTH NUMBER
MOV C, M
ADD C

; Store to 0x0005
STA 0005H

HLT