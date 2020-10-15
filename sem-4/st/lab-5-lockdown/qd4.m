pkg load symbolic;
clc;
clear all;

syms x;
f = (sin(5 * x)) / (sin(3 * x));

limit(f, x, 0)
