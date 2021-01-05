model small
.8086
.data
sum db ?
x db 54h
y db 14h

.code
mov ax, @data
mov ds, ax
mov al, x
sub al, y
mov sum, al
mov ax, 4c00h
int 21h
end
