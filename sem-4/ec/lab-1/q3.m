clc;
clear all;
close all;

t = -10:0.01:10;
d = zeros(1, length(t));
period = 1;

d(mod(t, period) == 0) = 1;
e = square(t * period);
f = sawtooth(t * period);
g = sawtooth(t * period, 0.5);

subplot(4, 1, 1);
plot(t, d);
axis([-10 10 -0.5 1.5]);
xlabel('time');
ylabel('amplitude');
title('impulse train');

subplot(4, 1, 2);
plot(t, e);
axis([-10 10 -1.5 1.5]);
xlabel('time');
ylabel('amplitude');
title('square wave');

subplot(4, 1, 3);
plot(t, f);
axis([-10 10 -1.5 1.5]);
xlabel('time');
ylabel('amplitude');
title('saw tooth wave');

subplot(4, 1, 4);
plot(t, g);
axis([-10 10 -1.5 1.5]);
xlabel('time');
ylabel('amplitude');
title('triangle wave');