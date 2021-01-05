
;<Roll Number Change>

jmp start

;data
name: db 85, 49, 56, 67, 79, 48, 50, 49
update: ds 11


;code
start: nop
lxi H, name
lxi D, update
; u
mov A, M
stax D
inx H
inx D
; g
mvi A, 47H
stax D
inx D
; next 4: 18CO
mvi c, 04H
loop: nop
mov A, M
stax D
inx H
inx D
dcr C
jnz loop
; e
mvi A, 45H
stax D
inx D
; d
mvi A, 44H
stax D
inx D
; last 3: 021
mvi C, 03H
loop2: nop
mov A, M
stax D
inx H
inx D
dcr C
jnz loop2
hlt