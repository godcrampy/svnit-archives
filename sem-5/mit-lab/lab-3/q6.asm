lda 4000H
lxi H, 4001H
add M
sta 4003H
jnc end
lxi H, 4002H
mvi M, 1
end: hlt