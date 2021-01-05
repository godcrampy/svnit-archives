
;<q1>

jmp start

;data
;code
start: nop
lxi SP, 4000H
mvi B, 4 ; factorial of this
nop
call factorial

hlt

; Factorial of B stored in D
; req: A
factorial: nop
mvi A, 1
cmp B
jnz next
mvi D, 1
ret
next: nop
dcr B
call factorial
inr B
mov C, D
call multiply
mov D, C
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