pkg load symbolic;
clc;
clear all;

syms x;
eqn = x^4 - 7 * x^3 + 3 * x^2 - 5 * x + 9 == 0;

S = solve(eqn);

ans = double(S);
ans
