clc;
clear all;

x = input("Enter n: ");
a = 0;
b = 1;

for i = 1:x
  n = a + b;
  a = b;
  b = n;
  printf("%d\n", b);
endfor
