model small

.8086
.data
quo db ?
rem db ?

.code
  mov ax,@data
  mov ds,ax
  mov ax, 0020h
  mov bl, 10h
  div bl
  mov quo, al
  mov rem, ah
  mov ax, 4c00h
  int 21h
end
