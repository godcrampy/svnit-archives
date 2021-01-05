
;<Gaonkar ch9q8>

jmp start

;data


;code
start: nop
lxi SP, 0099H
; clear data from 0090H to 009FH
lxi H, 0090H
lxi D, 0001H
mvi C, 10H
mvi A, 00H
loop: nop
mov M, A
dad D
dcr C
jnz loop
; load data
lxi B, 0237H
lxi D, 1242H
lxi H, 4087H
; push contents
push B
push D
push H
hlt