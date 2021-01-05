model small
.8086

.data
  cr equ 0dh
  lf equ 0ah
  msg db "First String: $"
  msg1 db cr,lf,"Second String: $"
  msg2 db cr,lf,"Concat: $"
  st1 db 80 dup('$')
  st2 db 80 dup('$')
  st3 db 80 dup('$')

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
  mov si,offset st2
  mov dh,00h
  u:
  mov ah,01h
  int 21h
  cmp al,0dh
  je s
  mov [si],al
  inc si
  inc dh
  jmp u
  s:
  mov si,offset st1
  mov di,offset st3
  me:
  mov dl,[si]
  mov [di],dl
  inc si
  inc di
  loop me
  mov si,offset st2
  go:
  mov dl,[si]
  mov [di],dl
  dec cx
  inc si
  inc di
  dec dh
  jnz go
  print msg2
  print st3
  mov ah,4ch
  int 21h
end