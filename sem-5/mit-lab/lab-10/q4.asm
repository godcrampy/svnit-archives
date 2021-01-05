model small

.8086
.data
  num dw 4
  fact dw ?

.code
  mov ax, @data
  mov ds, ax
  mov cx, num
  mov ax, 0001H
  up: nop
  mul cx
  dec cx
  jnz up
  mov fact, ax
  mov ah, 4ch
  int 21h
end