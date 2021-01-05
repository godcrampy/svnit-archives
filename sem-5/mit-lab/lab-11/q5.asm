.model small
.8086

.data
  p1 db "sahil$"
  p2 db 6 dup(0)

.code
  mov ax,@data
  mov ds,ax

  mov si,offset p1
  mov di,offset p2
  mov cx,0006h
  up:
  mov al,[si]
  mov [di],al
  inc si
  inc di
  dec cx
  jnz up
  mov ax,4c00h
  int 21h
end