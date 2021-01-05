model small

.8086
.data
  num dw 0003H
  cub dw ?

.code
  mov ax, @data
  mov ds, ax
  mov ax, num
  mov bx, ax
  mul ax
  mul bx
  mov cub, ax
  mov ah, 4ch
  int 21h
end
