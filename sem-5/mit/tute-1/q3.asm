
;<Copy and Sort>

jmp start

;data
name: db 85, 49, 56, 67, 79, 48, 50, 49
answer: ds 8

;code
start: nop
;copy
lxi H, name
lxi D, answer
mvi C, 08H
up: mov A, M
stax D
inx H
inx D
dcr C
jnz up
;sort

sort: lxi H, answer
mvi D, 00H
; array size
mvi C, 8
dcr C
check: mov A, M
inx H
cmp M
; A <= [M]
jc next
jz next
; swap
mov B, M
mov M, A
dcx H
mov M, B
inx H
mvi D, 01H
next: dcr C
jnz check
mov A, D
cpi 01H
jz sort
hlt