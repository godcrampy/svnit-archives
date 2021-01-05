
;<Program title>

jmp start

;data


;code
start: nop
mvi B, 0AH
mvi C, 0BH
mvi A, 00H
loop: nop
add B
dcr C
jnz loop
hlt