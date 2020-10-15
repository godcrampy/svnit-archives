clc;
clear all;
a = [1, 2, 3; 4, 5, 6; 7, 8, 9]

for i = 1:3
  for j = i:3
    temp = a(i, j);
    a(i, j) = a(j, i);
    a(j, i) = temp;
  end
end

a
