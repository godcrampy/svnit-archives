model small

.8086
.data
  msg db "Nibble palindrome$"
  msg1 db "Not nibble palindrome$"

print macro msg
  mov ah,09h
  mov dx,offset msg
  int 21h
endm

.code
  mov ax, @data
  mov ds, ax
  mov al, 44h
  mov bl, al
  mov cx, 0004h
  rol al, cl
  cmp al, bl
  je down
  print msg1
  jmp fin
  down: print msg
  fin: mov ah, 4ch
  int 21h
end