pkg load symbolic;
clc;
clear all;

syms x y z;
eqn = [x + y + z == 3, x + 2 * y + 3 * z == 4, x + 4 * y + 9 * z == 6];

S = solve(eqn, [x y z]);

x = double(S.x);
y = double(S.y);
z = double(S.z);
x
y
z
