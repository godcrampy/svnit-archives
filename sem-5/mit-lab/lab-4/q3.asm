
;<q3>

jmp start

;data


;code
start: nop
mvi B, 91H
mvi C, 87H
mov A, B
ani 01H
mov B, A
mov A, C
ani 01H
mov C, A


hlt