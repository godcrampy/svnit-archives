
;<Fetch Last 3 Numbers Advanced>

jmp start

;data
name: db 85, 49, 56, 67, 79, 51, 50, 49

;code
start: nop
lxi H, name
inx H
inx H
inx H
inx H
inx H
mov A, M
sui 48
; hundreds place
mov C, A
inx H
mov A, M
sui 48
; tens place
mov B, A
inx H
; units place
mov A, M
sui 48
lxi H, 0000H
; 1
mvi D, 00H
mov E, A
dad D
; 10
mvi A, 10
mov E, B
loop10: nop
dad D
dcr A
jnz loop10

; 100
mvi A, 100
mov E, C
loop100: nop
dad D
dcr A
jnz loop100
hlt