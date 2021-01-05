
;<q4b>

jmp start

;data


;code
start: nop
lxi H, 5000H
mov D, M
call sqr
lxi H, 5050H
mov M, C
hlt

; Store sqr of D in C
sqr: nop
mov B, D
mov C, D
call multiply
ret

; Multiply B & C and store in C
; req: A, B, C
multiply: nop
mvi A, 0
loop: nop
add B
dcr C
jnz loop
mov C, A
ret
