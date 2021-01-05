
;<q3>

jmp start

;data


;code
start: nop
mvi B, 04H
mvi C, 03H
call multiply
hlt

; Multiply B & C and store in D
; req: A, B, C
multiply: nop
mvi A, 0
loop: nop
add B
dcr C
jnz loop
mov D, A
ret