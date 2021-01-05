
;<q4>

jmp start

;data


;code
start: nop
; reset carry
stc
cmc
mvi B, 0FFH
inr B
mov A, B
jnc skip
mvi A, 01H
skip: nop
out 00H
hlt