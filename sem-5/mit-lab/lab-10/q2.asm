model small

.8086
.data
  lcm db ?
  lcm1 db ?

.code
  mov ax, @data
  mov ds, ax
  mov ax, 000CH
  mov cx, ax
  mov dx, ax
  mov bl, 10H
  up: div bl
  cmp ah, 00H
  je down
  mov ax, cx
  add ax, dx
  mov cx, ax
  jmp up
  down: mov lcm, ch
  mov lcm1, cl
  mov ah, 4CH
  int 21H
end
