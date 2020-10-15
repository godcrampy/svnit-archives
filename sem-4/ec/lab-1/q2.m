clc;
clear all;
close all;

t = -10:0.01:10;
d = zeros(1, length(t));
e = zeros(1, length(t));
f = zeros(1, length(t));

d(t == 0) = 1;
e(t >= 0) = 1;
f(t >= 0) = t(t >= 0);

subplot(3, 1, 1);
plot(t, d);
xlabel('time');
ylabel('amplitude');
title('impulse function');

subplot(3, 1, 2);
plot(t, e);
axis([-10 10 -1.5 1.5]);
xlabel('time');
ylabel('amplitude');
title('unit step function');

subplot(3, 1, 3);
plot(t, f);
xlabel('time');
ylabel('amplitude');
title('ramp function');
