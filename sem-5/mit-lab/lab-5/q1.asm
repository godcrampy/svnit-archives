
;<q1>

jmp start

;data


;code
start: nop
lxi H, 2070H
lxi B, 2090H
loop: nop
mov A, M
xri 0DH
jz exit
mov A, M
cpi 30H
jc skip
cpi 39H
jz go
jnc skip
go: stax B
inx B
skip: nop
inx H
jmp loop
exit: hlt