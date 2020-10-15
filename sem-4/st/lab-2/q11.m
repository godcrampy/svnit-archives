clc;
clear all;

x = input("Enter a number: ");
sum = 0;
y = x;

for i = 1:(x - 1)
  if mod(x, i) == 0
    x /= i;
    sum += i;
  end
end

if sum == y
  puts("Perfect Number\n");
else
  puts("Not Perfect Number \n");
end
