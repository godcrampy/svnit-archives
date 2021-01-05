model small

.8086
.data
  zero db ?
  one db ?

.code
  mov ax,@data
  mov ds,ax
  mov bx, 0000h
  mov al, 0FEh
  mov cl, 08h
  up: rol al,01
  jnc down
  inc bh
  dec cl
  jnz up
  jmp fin
  down: inc bl
  dec cl
  jnz up
  fin: nop
  mov zero, bh
  mov one, bl
  mov ah, 4ch
  int 21h
end