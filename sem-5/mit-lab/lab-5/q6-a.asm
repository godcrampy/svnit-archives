
;<q6a>

jmp start

;data


;code
start: nop
lxi H, 3000H
mvi D, 05H
lxi B, 4000H
loop: nop
mov A, M
stax B
inx H
inx B
dcr D
jnz loop
hlt