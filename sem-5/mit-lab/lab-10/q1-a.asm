model small

.8086
.data
  num dw 0012H
  sqr dw ?

.code
  mov ax, @data
  mov ds, ax
  mov ax, num
  mul ax
  mov sqr, ax
  mov ah, 4ch
  int 21h
end
