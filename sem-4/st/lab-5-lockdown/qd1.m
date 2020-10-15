pkg load symbolic;
clc;
clear all;

syms x;
f = (x^3 + 5) / (x^4 + 7);

limit(f, x, 0)
