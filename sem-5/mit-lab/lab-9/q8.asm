model small

.8086
.data
  source db "hello$"
  dest db 6 dup(0)

.code
  mov ax,@data
  mov ds,ax
  mov si, offset source
  mov di, offset dest
  mov cx, 0006h
  loop: nop
  mov al, [si]
  mov [di], al
  inc si
  inc di
  dec cx
  jnz loop
  mov ax, 4c00h
  int 21h
end