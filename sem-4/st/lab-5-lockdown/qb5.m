pkg load symbolic;
clc;
clear all;

syms x y;
eqn = [4 * x + 3 * y == -2, 8 * x - 2 * y == 12];

S = solve(eqn, [x y]);

x = double(S.x);
y = double(S.y);
x
y
