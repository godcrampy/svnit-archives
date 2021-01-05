model small

.8086
.data
  cr equ 0dh
  lf equ 0ah
  num db 3CH
  m1 db cr,lf, "Palindrome$"
  m2 db cr,lf,"Not a palindrome$"

print macro msg
  mov ah,09h
  mov dx,offset msg
  int 21h
endm

.code
  mov ax, @data
  mov ds, ax
  mov al, num
  mov bl, al
  mov cl, al
  mov dl, 00h
  mov ch, 07h
  up: nop
  and al, 01h
  or dl, al
  mov al, cl
  ror al, 01
  mov cl, al
  rol dl, 01
  dec ch
  jnz up
  cmp dl, bl
  je down
  print m2
  jmp eo
  down: print m1
  eo: mov ah,4ch
  int 21h
end