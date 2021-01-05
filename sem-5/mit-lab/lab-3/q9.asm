lhld 4002H
xchg
lhld 4000H
mov a,e
sub l
sta 4004H
mov a,d
sbb H
sta 4005H
hlt