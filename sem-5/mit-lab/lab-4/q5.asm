
;<q5>

jmp start

;data


;code
start: nop
; 8 bit number
mvi B, 0A5H
mov A, B
ani 0FEH
hlt