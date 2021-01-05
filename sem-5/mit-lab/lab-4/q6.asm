
;<q6>

jmp start

;data


;code
start: nop
mvi B, 0F8H
mvi C, 023H
mov A, B
sub C
jc skip
out 01H
hlt
skip: nop
cma
adi 01H
out 01H
hlt