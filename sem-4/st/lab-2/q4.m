clear all;
clc;

a = [1, 2, 3; 4, 5, 6; 7, 8, 9]
b = [8, 6, 7; 4, 3, 1; 6, 6, 2]

c = ones(3, 3);
d = zeros(3, 3);

for i = 1:3
  for j = 1:3
    c(i, j) = a(i, j) + b(i, j);
  end
end

c
cols_a = size(a)(1, 2);
rows_a = size(a)(1, 1);
cols_b = size(a)(1, 2);
rows_b = size(a)(1, 1);

if cols_a != rows_b
  puts("Invalid Multiplication\n");
  break;
 end;
 
for i = 1:rows_a
  for j = 1:cols_b
    for k = 1:cols_a
      d(i, j) += a(i, k) * b(k, j);
    end 
  end
end

d
a * b