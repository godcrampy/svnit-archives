pkg load symbolic;
clc;
clear all;

syms x;
f = (1 - x^(0.5)) / (1 - x);

limit(f, x, 0)
