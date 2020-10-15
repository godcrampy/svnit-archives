## Question 1

clc;

clear all;
close all;

t = -10:0.01:10;

x = sin(t);
y = cos(t);
z = tan(t);
w = exp(t);

% figure;
subplot(2, 2, 1);
plot(t, x);
xlabel('time');
ylabel('amplitude');
title('sin wave');

% figure;
subplot(2, 2, 2);
plot(t, y);
xlabel('time');
ylabel('amplitude');
title('cos wave');

% figure;
subplot(2, 2, 3);
plot(t, z);
axis([-pi/2 pi/2 -50 50]);
xlabel('time');
ylabel('amplitude');
title('tan wave');
% figure;

subplot(2, 2, 4);
plot(t, w);
xlabel('time');
ylabel('amplitude');
title('exp curve');

## Question 2

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

## Question 3

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
