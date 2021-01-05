
;<Program title>

jmp start

;data


;code
start: nop
; initial value
lxi H, 2000H
mvi M, 12
lxi H, 4000H
mvi M, 20

; swap
mov E, M
lxi H, 2000H
mov L, M
xchg
mov D, L

; store swapped values
lxi H, 4000H
mov M, E
lxi H, 2000H
mov M, D


hlt