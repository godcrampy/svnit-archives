clc;
clear all;

p = [1 -6 11 -6];

valueAtThree = polyval(p, 3)

roots = roots(p)

x = [0:0.1:20];
plot(x, polyval(p, x));