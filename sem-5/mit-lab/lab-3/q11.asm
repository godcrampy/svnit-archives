mvi B, 12H
mvi C, 34H
mvi E, 42H
mvi A, 00H
mov A, B
ana C
ana E
sta 3000H
mov A, B
ora C
ora E
sta 3001H
mov A, B
xra C
xra E
sta 3002H
hlt