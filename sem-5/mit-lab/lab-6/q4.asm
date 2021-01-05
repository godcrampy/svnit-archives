
;<q4>

jmp start

;data


;code
start: nop
lxi H, 5000H
mov D, M
call sqrt
lxi H, 5050H
mov M, E
hlt

; Store sqrt of D in E
sqrt: nop
mvi H, 01H ; counter
loop1: nop
mov B, H
mov C, H
call multiply
mov A, C
cmp D
jnz end
mov E, B
ret
end: nop
inr H
mov A, D
cmp H
jnz loop1
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
