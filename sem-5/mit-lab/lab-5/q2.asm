
;<q2>

jmp start

;data


;code
start: nop
lxi H, 2050H
mvi D, 0AH
lxi B, 2060H
loop: nop
mov A, M
cpi 03CH
jc skip
cpi 64H
jnc skip
stax B
inx B
skip: nop
inx H
dcr D
jnz loop
hlt