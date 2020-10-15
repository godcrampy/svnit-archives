pkg load symbolic;
clc;
clear all;

syms x;
f = (x - 3) / (x - 1);

limit(f, x, 1)
