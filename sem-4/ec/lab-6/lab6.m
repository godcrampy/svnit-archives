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

subplot(3, 2, 1);
plot(t, m);
xlabel('Time (t)');
title('m(t)');

subplot(3, 2, 3);
plot(t, c);
xlabel('Time (t)');
title('c(t)');

subplot(3, 2, 5);
plot(t, s);
xlabel('Time (t)');
title('s(t)');

subplot(3, 2, 2);
plot(f, abs(ftm));
xlabel('Frequency (f)');
title('M(f)');

subplot(3, 2, 4);
plot(f, abs(ftc));
xlabel('Frequency (f)');
title('C(f)');

subplot(3, 2, 6);
plot(f, abs(fts));
xlabel('Frequency (f)');
title('S(f)');

% Demodulation
demt = s .* c;
demf = fftshift(fft(demt));

[B, A] = butter(3, fm/fs, 'low');
yt = filter(B, A, demt);
yf = fftshift(fft(yt));

figure;
subplot(2, 2, 1);
plot(t, demt);
xlabel('Time (t)');
title('Demodulation (Time)');

subplot(2, 2, 2);
plot(f, abs(demf));
xlabel('Frequency (f)');
title('Demodulation (Frequency)');

subplot(2, 2, 3);
plot(t, yt);
xlabel('Time (t)');
title('Demodulation & Filter (Time)');

subplot(2, 2, 4);
plot(f, abs(yf));
xlabel('Frequency (f)');
title('Demodulation & Filter (Frequency)');

figure;
plot(t, 7*m, t, -1*yt);
legend('Message Signal', 'Demodulated Signal');
