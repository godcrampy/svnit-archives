
;<q1>

jmp start

;code
start: nop
mvi D, 03H
lxi B, 2000H; start location
lxi H, 3000H; end location
first: ldax B
call pwr
inx h
inx b
dcr d
jnz first
hlt


pwr: nop
mvi e, 64H
call bcd
mvi e, 0AH
call bcd
mov m, a
ret


bcd: nop
mvi m, 0FFH
next: inr m
sub e
jnc next
add e
inx h
ret