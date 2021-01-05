
;<q6-b>

jmp start

;data


;code
start: nop
lxi H, 3000H
lxi B, 0006H
lxi D, 3004H
dad B
dcx H
xchg
dad B
dcx H
xchg
loop: nop
mov A, M
stax D
dcx D
dcx H
dcr C
jnz loop
hlt