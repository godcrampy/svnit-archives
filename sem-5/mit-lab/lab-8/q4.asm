model small
.8086
.data
sum db ?
sum1 db ?

.code
mov ax, @data
mov ds, ax
mov ah, 12h
mov al, 34h
mov bh, 11h
mov bl, 11h
sub al, bl
sbb ah, bh
mov sum, al
mov sum1, ah
mov ax, 4c00h
int 21h
end
