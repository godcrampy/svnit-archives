pkg load symbolic;
clc;
clear all;

syms x;
eqn = 6 * x^5 - 41 * x^4 + 97 * x^3 - 97 * x^2 + 41 * x - 6 == 0;

S = solve(eqn);

ans = double(S);
ans
