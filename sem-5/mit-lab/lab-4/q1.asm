
;<q1>

jmp start

;data


;code
start: nop
mvi C, 0A8H
mvi A, 0FH
ana C
out 00H
hlt