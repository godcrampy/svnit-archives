
;<Fetch Last 3 Numbers>

jmp start

;data
name: db 85, 49, 56, 67, 79, 48, 50, 49

;code
start: nop
lxi H, name
inx H
inx H
inx H
inx H
inx H
; hundreds place
mvi C, 100
mvi A, 00H
loop100: nop
add M
; ascii
sui 48
dcr C
jnz loop100

; tens place
inx H
mvi C, 10
loop10: nop
add M
; ascii
sui 48
dcr C
jnz loop10

; units place
inx H
add M
; ascii
sui 48
hlt