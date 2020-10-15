pkg load symbolic;
clc;
clear all;

syms x;
eqn = ((x - 3)^2) * (x - 7) == 0;

S = solve(eqn);

ans = double(S);
ans
