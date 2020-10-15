clc;
clear all;

x = [1:0.1:100];

y = log(x);
z = sin(x);

plot(x, y, ':', x, z, '.');
legend('first curve', 'second curve');
