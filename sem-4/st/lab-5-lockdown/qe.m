pkg load symbolic;
clc;
clear all;

syms x;
f = (x - 3) / abs(x - 3);

left_limit = limit(f, x, 3,  'left')
right_limit = limit(f, x, 3,  'right')
left_limit == right_limit

t = [-10:0.1:10];
y = (t - 3) ./ abs(t - 3);

plot(t, y)
axis([-10 10 -2 2])
