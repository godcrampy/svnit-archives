clc
clear all
fs=100;
t=-10:(1/fs):10;
fm=1;
am=5;
ac=5;
wm=2*pi*fm;
fc=10;
wc=2*pi*fc;
m=am*cos(wm*t);
c=ac*cos(wc*t);
kp=1;
kf=2*pi*fm;

F = griddedInterpolant(t,m);
fun = @(l) F(l);

s1=ac*cos(wc*t+(kp*m));
s2=ac*cos((wc*t)+(kf*fun(t)));
s3=[diff(m) 0];


subplot(5,1,1);
plot(t,m);
title('message signal');
subplot(5,1,2);
plot(t,c);
title('carrier signal');
subplot(5,1,3);
plot(t,s1);
title('PM Wave');
subplot(5,1,4);
plot(t,s3);
title('Derivative of message signal');
subplot(5,1,5);
plot(t,s2);
title('FM Signal');

n=length(t);
disp(n);
df=fs/n;
fp=(-fs/2):df:(fs/2)-df;
y1=fftshift(fft(s1));
y2=fftshift(fft(s2));
figure;
subplot(2,1,1);
plot(fp,y1);
title('Frequency Spectrum of PM');
subplot(2,1,2);
plot(fp,y2);
title('Frequency Spectrum of FM');

dfm=[diff(s2) 0];

s4=dfm.*c;
[b,a] = butter(4,fm/fs,'low');
y=filter(b, a, s4);

figure;
subplot(3,1,1);
plot(t,dfm);
title('Derivative of FM Signal');
subplot(3,1,2);
plot(t,s4);
title('Multiplaction of carrier with derivative of FM Signal');
subplot(3,1,3);
plot(t,m, t, y);
title('Filtered output and input signal');
