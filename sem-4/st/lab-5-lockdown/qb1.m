pkg load symbolic;
clc;
clear all;

syms x y;
eqn = [5 * x + 9 * y == 5, 3 * x - 6 * y == 4];

S = solve(eqn, [x y]);

x = double(S.x);
y = double(S.y);
x
y
