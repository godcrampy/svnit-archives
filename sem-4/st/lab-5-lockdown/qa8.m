clc;
clear all;

p = [8 -7 12 -5 8 13 0 -12 9];

disp("f(2)");
polyval(p, 2)

roots = roots(p)

t = [0:0.1:20];
plot(t, polyval(p, t))
