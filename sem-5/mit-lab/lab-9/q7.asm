model small

.8086
.data
d1 db "ABCDEF$"
d2 db "123$"

.code
  mov ax, @data
  mov ds, ax
  mov ah, 02h
  mov bh, al
  mov di, offset d2
  mov bl, [di]
  mov ax, [0011h]
  mov si, offset d1
  mov dl, [si + 4]
  mov ax, 4c00h
  int 21h
end