pkg load symbolic;
clc;
clear all;

syms x y z;
eqn = [x + 3 * y - 2 * z == 5, 3 * x + 5 * y + 6 * z == 7, 2 * x + 4 * y + 3 * z == 8];

S = solve(eqn, [x y z]);

x = double(S.x);
y = double(S.y);
z = double(S.z);
x
y
z
