model small

.8086
.data
  str db "123456$"

.code
  mov ax, @data
  mov ds, ax
  mov si, offset str
  mov cx, 0006h
  mov bl, 05h
  mov di, offset [str + 3]
  up: nop
  inc si
  inc di
  dec bl
  jnz up
  go: nop
  mov al, [si]
  mov [di], al
  dec si
  dec di
  dec cx
  jnz go
  mov ax, 4c00h
  int 21h
end