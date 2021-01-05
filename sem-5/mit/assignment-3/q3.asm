
;<Count Number of elements less than 09H>

jmp start

;data


;code
start: nop
; size of array
mvi C, 08H
; array location
lxi H, 3000H
; counter
mvi B, 0
; given number
mvi D, 09H
loop: nop
mov A, M
cmp D
jnc skip
inr B
skip: nop
dcr C
inx H
jnz loop
hlt