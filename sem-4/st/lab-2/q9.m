clc;
clear all;

a = [1, 2, 3, 4; 5, 6, 7, 8; 9, 10, 11, 12; 13, 14, 15, 16]

for i = 1:3
  for j = 1:3
    if isprime(a(i, j))
      printf("%d: (%d, %d)\n", a(i, j) ,i , j);
    end
  end
end
