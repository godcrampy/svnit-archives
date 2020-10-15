clc;
clear all;
T_0 = pi;
N = 100;

w_0 = 2 * pi / T_0;

w = [-N:N] * w_0;
t = [-4 * pi:0.1:4 * pi];

x = exp(-t/2);

fun = @(x)