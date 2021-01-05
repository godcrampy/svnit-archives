.model small

.data
  max dw ?
  min dw ?
  nums dw 1111H, 0EEFFH, 0EFFFH, 2222H, 9999H

.code
  mov ax,@data
  mov ds,ax
  mov si, offset nums ; init si to start of nums
  mov ax, [si]
  mov dx, [si]
  mov cx, 05H  ;counter
  up:
  cmp ax, [si]
  jnc next
  mov ax, [si]
  next:
  cmp dx, [si]
  jc skip
  mov dx, [si]
  skip:
  inc si
  inc si
  loop up
  mov max, ax
  mov min, dx
  mov ah, 4ch
  int 21h
end