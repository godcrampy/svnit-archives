pkg load symbolic;
clc;
clear all;

syms x;
eqn = 6 * x^2 + 11 * x - 35 == 0;

S = solve(eqn);

ans = double(S);
ans
