
;<Program title>

jmp start

;data


;code
start: nop
lxi H,4000H
mov E,M
inx H
mov D,M
inx H
mov C,M
inx H
mov B,M
mov H,B
mov L,C
dad D
shld 4004H

hlt