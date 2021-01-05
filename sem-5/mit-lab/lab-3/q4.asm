
;<Program title>

jmp start

;data


;code
start: nop
lda 2000H
lxi H, 4000H
mov B, M
sub B
sta 4002H

hlt