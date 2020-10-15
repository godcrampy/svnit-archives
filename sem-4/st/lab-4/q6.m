clc;
clear all;

x = [-10:0.1:10].';
y = 3*x.^4 + 2*x.^3 + 7*x.^2 + 2*x + ones(size(x))*9;
plot(x, y);
title("Polynomial");