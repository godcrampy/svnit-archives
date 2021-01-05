model small

.8086
.data
sum db ?
x db 20h
y db 30h

.code
mov ax, @data
mov ds, ax
mov al, x
add al, y
mov sum,al
mov ax, 4c00h
int 21h
end
