x = input("Enter a number: ");

number_of_digits =  ceil(log10(abs(x + 1)));
a = zeros(1, number_of_digits);

for i = 1:number_of_digits
  a(1, number_of_digits - i + 1) = mod(x, 10);
  x = floor(x / 10);
end

first = a(1, 1)
last = a(1, number_of_digits)
max = max(a)