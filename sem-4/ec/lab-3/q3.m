clc;
clear all;
close all;

T0 = 2 * pi;
N = 100;
w0 = 2*pi / T0;
t = -4 * pi : 0.01 : 4 * pi;
w = (-N: N) * (2 * pi / T0);

for i = 1:length(w)
    D(i) = i / T0 * integral(@(t)sin(t).*exp(-1j*w(i)*t), 0, T0);
end

figure;
subplot(3, 1, 1);
stem(w, abs(D));
xlabel('Angular Frequency (w)');
ylabel('Magnitude |Dn|');
title('Magnitude Spectrum');

subplot(3, 1, 2);
stem(w, angle(D));
xlabel('Angular Frequency (w)');
ylabel('Angle of D');
title('Phase Spectrum');

sum = 0;
for i = 1:length(w)
    sum = sum + D(i)*exp(j*w(i)*t);
end

subplot(3, 1, 3);
plot(t, sum);
xlabel('t');
ylabel('G(t)');
title('Synthesis of Signal from Sin Curve Fourier Series');

