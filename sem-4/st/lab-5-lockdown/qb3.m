pkg load symbolic;
clc;
clear all;

syms x y z;
eqn = [7 * x + 5 * y - 3 * z == 16, 3 * x - 5 * y + 2 * z == -8, 5 * x + 3 * y - 7 * z == 0];

S = solve(eqn, [x y z]);

x = double(S.x);
y = double(S.y);
z = double(S.z);
x
y
z
