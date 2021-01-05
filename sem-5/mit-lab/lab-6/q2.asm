
;<q2>

jmp start

;data


;code
start: nop
lxi H, 4000H
mvi B, 07H
call fib

hlt

; calclates first [B] = n fibonacci numbers
; req: A, B, M, C
fib: nop
mvi C, 0 ; counter
loop: nop
mvi A, 00H
cmp C
jnz skip
mvi M, 00H
jmp next
skip: nop
mvi A, 01H
cmp C
jnz skip2
mvi M, 01H
jmp next
skip2: nop
dcx H
mov A, M
dcx H
add M
inx H
inx H
mov M, A
next: inx H
inr C
mov A, C
cmp B
jnz loop
ret