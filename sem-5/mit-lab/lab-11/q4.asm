.model small

.8086
.data
  cr equ 0dh
  lf equ 0ah
  msg db "Enter data: $"
  msg1 db cr,lf,"Enter a search charecter:$"
  msg2 db cr,lf,"Frequency: $"
  c db ?
  st1 db 80 dup('$')
  cnt db 0h
  
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
  jmp e
  down:
  inc cnt
  inc si
  loop u
  e:
  print msg2
  mov ah,02h
  mov dh,00h
  mov dl,cnt
  add dl,30h
  int 21h
  mov ah,4ch
  int 21h
end