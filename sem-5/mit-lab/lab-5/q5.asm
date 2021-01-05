
;<q5>

jmp start

;data


;code
start: nop
lxi H, 3000H
; counter
mvi C, 08H
mvi B, 0FFH
mvi D, 00H
loop: nop
mov A, M
cmp B
jnc skip
mov B, A
skip: nop
cmp D
jc skip2
mov D, A
skip2: nop
inx H
dcr C
jnz loop
hlt