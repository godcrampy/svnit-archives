model small

.8086
.data
  gcd db ?

.code
  mov ax, @data
  mov ds, ax
  mov al, 0CH
  mov bl, 10H
  up: mov cl,al
  cmp cl, bl
  je down
  jnc go
  sub bl, al
  jmp up
  go: sub al, bl
  jmp up
  down: mov gcd, al
  mov ah, 4ch
  int 21h
end