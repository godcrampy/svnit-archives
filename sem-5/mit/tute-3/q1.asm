
;<Program title>

jmp start

;data


;code
start: nop
lxi SP, 27ffh
call inc
inc: pop H
hlt