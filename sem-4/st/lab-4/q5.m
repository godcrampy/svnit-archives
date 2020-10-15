clc;
clear all;

x = [-10:0.1:10];

y1 = ones(size(x))*2 - (x - ones(size(x))*3).^2;
y2 = x / 2 + ones(size(x));

plot(x, y1, x, y2);