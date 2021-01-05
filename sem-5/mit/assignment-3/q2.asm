
;<Number of set bits in B>

jmp start

;data


;code
start: nop
mvi B, 0BH
; loop 8 times
mvi C, 8
mov A, B
; counter for number of bits
mvi D, 0
loop: nop
rrc
jnc skip
; increase count if bit is set
inr D
skip: nop
; decrease loop conuter
dcr C
jnz loop
hlt