clc;
clear all;

[x, y] = meshgrid(-8:0.1:8, -8:0.1:8);

r = sqrt(x.^2 + y.^2);
z = sin(r)/r;
mesh(x, y, z);