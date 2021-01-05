model small

.8086
.data
  string db "Positive Number$"
  string1 db "Negative Number$"
  num db 0012H

.code
  mov ax, @data
  mov ds, ax
  mov al, num
  rol al, 01
  jc down
  mov ah, 09h
  mov dx, offset string
  int 21h
  jmp fin
  down: mov ah,09h
  mov dx, offset string1
  int 21h
  fin: mov ah, 4ch
  int 21h
end