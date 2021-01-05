
;<q2>

jmp start

;data


;code
start: nop
mvi E, 0AH
lxi SP, 7000H
lxi H, 4000H
lxi B, 5000H
first: mov A, M
call bcd
stax B
inx B
inx H
dcr E
jnz first
xra A
mvi E, 0AH
lxi B, 5000H
lxi H, 0000H
loop: ldax B
push D
mov E, A
dad D
inx B
pop D
dcr E
jnz loop
shld 6000H
hlt


bcd: push B
push D
mov B, A
ani 0FH
mov C,A
mov A, B
ani 0F0H
jz bcd1
rrc
rrc
rrc
rrc
mov D, A
xra A
mvi E, 0AH
sum: add E
dcr D
jnz sum
bcd1: add C
pop D
pop B
ret
