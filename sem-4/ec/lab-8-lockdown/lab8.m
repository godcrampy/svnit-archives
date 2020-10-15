clear all;
clc;

vm = 5;
vc = 10;

fm = 1;
fc = 10;
fs = 100;
wm = 2*pi*fm;
wc = 2*pi*fc;

t = -2:1/fs:2;
n = length(t);
df = fs / n;
f = -fs/2:df:fs/2 - df;

% Modulation
m = vm*cos(wm*t);
c = vc*cos(wc*t);
s = m .* c;

ftm = fftshift(fft(m));
ftc = fftshift(fft(c));
fts = fftshift(fft(s));

subplot(3, 1, 1);
plot(t, m);
xlabel('Time (t)');
ylabel('m(t)');
title('Message Signal');

subplot(3, 1, 2);
plot(t, c);
xlabel('Time (t)');
ylabel('c(t)');
title('Carrier Signal');

subplot(3, 1, 3);
plot(t, s);
xlabel('Time (t)');
ylabel('s(t)');
title('AM Signal');

figure;
subplot(3, 1, 1);
plot(f, abs(ftm));
xlabel('Frequency (f)');
ylabel('M(f)');
title('Message Signal in Frequency Domain');

subplot(3, 1, 2);
plot(f, abs(ftc));
xlabel('Frequency (f)');
ylabel('C(f)');
title('Carrier Signal in Frequency Domain');

subplot(3, 1, 3);
plot(f, abs(fts));
xlabel('Frequency (f)');
ylabel('S(f)');
title('AM Signal in Frequency Domain');

% Demodulation
demt = s .* c;
demf = fftshift(fft(demt));

[B, A] = butter(3, fm/fs, 'low');
yt = filter(B, A, demt);
yf = fftshift(fft(yt));

figure;
subplot(2, 1, 1);
plot(t, demt);
xlabel('Time (t)');
ylabel('Demodulation (Time)');
title('Multiplication with Carrtier');


subplot(2, 1, 2);
plot(t, 7*m, t, -1*yt);
legend('Message Signal', 'Demodulated Signal');
title('Filtered Input & Output Signal');
