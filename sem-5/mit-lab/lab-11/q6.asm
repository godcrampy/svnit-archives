model small
.8086

.data
  cr equ 0dh
  lf equ 0ah
  msg db "Enter string: $"
  msg1 db cr,lf, "String: $"
  msg2 db cr,lf,"Reverse: $"
  st1 db 80 dup('$')
  st2 db 80 dup('$')
  print macro msg
  mov ah,09h
  mov dx,offset msg
  int 21h
endm

.code
  mov ax,@data
  mov ds,ax
  print msg
  mov si,offset st1
  mov cx,0000h
  up:
  mov ah,01h
  int 21h
  cmp al,0dh
  je stp
  mov [si],al
  inc si
  inc cx
  jmp up
  stp:
  print msg1
  print st1
  mov si,offset st1
  add si,cx
  dec si
  mov di,offset st2
  m:
  mov bl,[si]
  mov [di],bl
  dec si
  inc di
  dec cx
  jnz m
  print msg2
  print st2
  mov ah,4ch
  int 21h
end