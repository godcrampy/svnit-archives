
;<Bubble Sort Descending>

jmp start

;data
name: db 85, 49, 56, 67, 79, 48, 50, 49

;code
start: lxi H, name
mvi D, 00H
; array size
mvi C, 8
dcr C
check: mov A, M
inx H
cmp M
; A >= [M]
jnc next
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
jz start
hlt