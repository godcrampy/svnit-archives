.model small

.data
  sum dw ?
  carry db ?
  nums dw 0011h, 0022h, 0033h, 0044h, 0055h

.code
  mov ax,@data
  mov ds,ax

  mov ax, 0000H
  mov cx, 05H ; counter
  mov bl, 00H ; to count carry
  mov si, offset nums ; init si to start of nums
  up:
  add ax, [si]
  jnc skip
  inc bl ;
  skip:
  inc si
  inc si
  loop up
  mov sum, ax
  mov carry, bl

  mov ah, 4ch
  int 21h
end