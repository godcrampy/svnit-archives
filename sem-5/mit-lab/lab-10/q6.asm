model small

.8086
.data
  cr equ 0dh
  lf equ 0ah
  m db "Enter a number:$"
  string db cr, lf, "Even Number$"
  string1 db cr, lf, "Odd Number$"
  num db ?

print macro string
  mov ah, 09h
  mov dx, offset string
  int 21h
endm

read macro no
  mov ah, 01h
  int 21h
  sub al, 30h ; ascii
  mov bl, 0ah ; x10
  mul bl
  mov no, al
  mov ah, 01h
  int 21h
  sub al, 30h ; ascii
  add no, al
endm

.code
  mov ax,@data
  mov ds,ax
  print m
  read num
  mov ah,00h
  mov al,num
  mov bl,02h
  div bl
  cmp ah,00h
  je down
  mov ah,09h
  mov dx, offset string1
  int 21h
  jmp eo
  down: mov ah,09h
  mov dx, offset string
  int 21h
  eo: mov ah,4ch
  int 21h
end