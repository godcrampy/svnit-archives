clc;
clear all;

a = [1, 2, 3, 4; 5, 6, 7, 8; 9, 10, 11, 12; 13, 14, 15, 16]

for i = 1:3
  for j = 1:3
    if mod(a(i, j), 5) == 0 || mod(a(i, j), 7) == 0
      printf("(%d, %d)\n", i, j);
    end
  end
end
