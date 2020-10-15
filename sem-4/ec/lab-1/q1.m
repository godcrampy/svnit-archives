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
