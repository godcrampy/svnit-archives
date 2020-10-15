clc;
% Question 1 to 10

a = [1, 2, 3; 4, 5, 6; 7, 8, 9]
b = [4, 6, 7; 5, 6, 1; 2, 6, 3]

c = a + b
d = a * b
e = a .* b
f = a .^ 2
g = b .^ 2

a(1, :)
b(:, 3)

det_b = det(b)
inv_b = inv(b)