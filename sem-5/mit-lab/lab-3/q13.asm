lhld 3000H
mov A, L
cma 
mov L, A
mov A, H
cma
mov H, A
inx H
shld 3002H
hlt