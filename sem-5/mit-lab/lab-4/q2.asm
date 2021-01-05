
;<q2>

jmp start

;data


;code
start: nop
mvi D, 8EH
mvi E, 0F7H
mov A, D
ani 0FH
mov D, A
mov A, E
ani 0FH
mov E, A
xra D
out 00H
hlt