.model small

.8086
.data
  a dw 7
  b dw -0002
  prod dw ?

.code
  mov ax, @data
  mov ds, ax

  mov ax, a
  mov bx, b
  imul bx
  mov prod, ax

  mov ah, 4ch
  int 21h
end