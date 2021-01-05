
;<Check 4th bit set>

jmp start

;data


;code
start: nop
lda 3000H
rrc
rrc
rrc
rrc
lxi H, 3002H
mvi B, 0
mov M, B
jnc end 
mvi B, 0FFH
mov M, B
end: hlt