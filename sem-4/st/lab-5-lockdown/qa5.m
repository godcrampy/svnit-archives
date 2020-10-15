pkg load symbolic;
clc;
clear all;

syms x;
eqn = (x - 2)^2 -12 == 0;

S = solve(eqn);

ans = double(S);
ans
