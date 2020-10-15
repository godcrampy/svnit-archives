clc
clear all
b = input('Enter the Bit stream \n ');
n = length(b);%defining n
t = 0:.01:n;%defining t
x = 1:1:(n+1)*100;%defining x
%using for loop
for i = 1:n
for j = i:.1:i+1
bw(x(i*100:(i+1)*100)) = b(i);

end
end
bw = bw(100:end);
sint = sin(2*pi*t);
st = bw.*sint;
%Plotting all using subplot
subplot(3,1,1)
plot(t,bw)
grid on ; axis([0 n -2 +2])
subplot(3,1,2)
plot(t,sint)
grid on ; axis([0 n -2 +2])
subplot(3,1,3)
plot(t,st)
grid on ; axis([0 n -2 +2])