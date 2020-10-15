clc;
clear all;

fs = 100;
t = 0:1/fs:8;
fc = 2;

wc = 2*pi*fc;
c  = sin(wc*t);

m = t;
bs = [0 1 1 0 1 1 1 0];

for i=1:length(t)
    m(i) = bs(mod(floor(t(i)), 8) + 1);
end

subplot(3, 1, 1);
plot(t, m);
axis([0 8 -2 2]);

subplot(3, 1, 2);
plot(t, c);
axis([0 8 -2 2])

subplot(3, 1, 3);
plot(t, m .* c);
axis([0 8 -2 2])