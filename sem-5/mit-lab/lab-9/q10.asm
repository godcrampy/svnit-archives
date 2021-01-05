model small

.8086
.data
  str1 db "hello$"
  str2 db "world$"

.code
  mov ax, @data
  mov ds, ax
  mov si, offset str1
  mov di, offset str2
  mov cx, 0006h
  loop: nop
  mov al, [si]
  mov bl, [di]
  mov [si], bl
  mov [di], al
  inc si
  inc di
  dec cx
  jnz loop
  mov ax,4c00h
  int 21h
end