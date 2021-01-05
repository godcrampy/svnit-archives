
;<q3>

jmp start

;data


;code
start: nop
mvi D,03H
lxi H,4000H
lxi B,5000H
first: nop
mov A, M
call asctobin
stax B
dcr D
inx H
inx B
jnz first
lxi H, 5000H
mvi D, 03H
mvi A, 00H
up: mov E, M
add E
dcr D
inx H
jnz up
sta 6000H
hlt

asctobin: sui 30H
cpi 0AH
rc
sui 07H
ret
