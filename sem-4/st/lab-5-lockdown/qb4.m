pkg load symbolic;
clc;
clear all;

syms x y;
eqn = [3 * x + 2 * y == 16, 7 * x + y == 19];

S = solve(eqn, [x y]);

x = double(S.x);
y = double(S.y);
x
y
