clc
clear all
fm=1;%defining fm
fs=20*fm;%defining fs
t=-3:(1/fs):3;%defining t
am=1;%defining am
m=am*cos(2*pi*fm*t);%the message signal
del=(2*pi*fm*am)/fs;%defining del
%Running a for loop
for i=1:length(t)
    if(i==1)
        mq=0;
        d(i)=m(i);
        dq=(sign(d))*del;
        mq=dq;
    else
        d(i)=m(i)-mq(i-1);
        dq=(sign(d))*del;
        mq(i)=dq(i)+mq(i-1);
    end
end
%plotting
plot(t,m);
%holding
hold on;
stairs(t,mq);
title('message signal and staircase approximation of message signal');%title of plot
%running for loop
for n=1:length(t)
if(d(n)>0)
    dm(n)=1;
else
    dm(n)=-1;
end
end
%another figure
figure
stem(t,dm);
title('Delta modulated signal');%title of plot
n=1;
wn=fm/fs;%defining wn
[b a]=butter(n,wn,'low');
y=filter(b,a,mq);%y is output of filter
%plotting again
figure
plot(t,2*y,t,m);
title('filtered output signal');%title of the plot