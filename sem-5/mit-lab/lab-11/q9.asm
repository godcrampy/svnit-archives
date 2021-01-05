model small
.8086

.data
  cr equ 0dh
  lf equ 0ah
  msg db "Enter String: $"
  msg1 db cr,lf,"Enter Search Charecter: $"
  msg2 db cr,lf,"Found!$"
  msg3 db cr,lf,"Not Found$"
  c db ?
  st1 db 80 dup('$')

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
  mov ah,01h
  int 21h
  mov c,al
  mov si,offset st1
  u:
  mov bl,[si]
  cmp c,bl
  jz down
  inc si
  loop u
  print msg3
  jmp e
  down:
  print msg2
  e: mov ah,4ch
  int 21h
end