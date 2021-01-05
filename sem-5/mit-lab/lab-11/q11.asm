model small
.8086

.data
  cr equ 0dh
  lf equ 0ah
  msg db "Enter String: $"
  msg1 db cr,lf,"Enter Substring: $"
  msg2 db cr,lf,"Found!$"
  msg3 db cr,lf,"Not Found$"
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
  mov si,offset st2
  mov bx,0000h
  u:
  mov ah,01h
  int 21h
  cmp al,0dh
  je stop
  mov [si],al
  inc si
  inc bx
  jmp u
  stop:
  mov si,offset st1
  mov di,offset st2
  cmp cx,bx
  jc down
  mov dx,0000h
  go:
  mov al,[si]
  cmp al,[di]
  je me
  mov dx,0000h
  mov di,offset st2
  inc si
  loop go
  jmp en
  me:
  inc dx
  inc si
  inc di
  cmp dx,bx
  jnz go
  en:
  cmp dx,bx
  jnz down
  print msg2
  jmp e
  down:
  print msg3
  e: mov ah,4ch
  int 21h
end