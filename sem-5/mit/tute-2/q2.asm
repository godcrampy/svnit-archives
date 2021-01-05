
;<Gaonkar ch9q9>

jmp start

;data


;code
start: nop
; clear flags
lxi SP, 0040H
lxi B, 0000H
push B
pop PSW
; increment using adi
mvi A, 00FFH
adi 01H
; move PSW to BC
push PSW
pop B
; mask C flag
mvi A, 01H
ana C
; out port0
out 00H

; increment using adi
mvi A, 00FFH
inr A
; move PSW to BC
push PSW
pop B
; mask C flag
mvi A, 01H
ana C
; out port0
out 01H

hlt