x = input("Enter a Number: ");

number_of_digits =  ceil(log10(abs(x + 1)));

reverse = 0;

for i = 1:number_of_digits
  reverse += mod(x, 10) * (10 ^ (number_of_digits - i));
  x = floor(x / 10);
end

reverse
