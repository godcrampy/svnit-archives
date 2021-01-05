model small

.8086
.data
quo db ?
rem db ?

.code
mov ax,@data
mov ds,ax
mov ax, 1234H
mov bx, 22H
div bx
mov quo, al
mov rem, ah
mov ax, 4c00h
int 21h
end