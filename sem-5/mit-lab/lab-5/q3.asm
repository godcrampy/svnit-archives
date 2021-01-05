
;<q3>

jmp start

;data
;code
start: nop
lxi H, 2050H
lxi B, 0010H
lxi D, 2055H
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