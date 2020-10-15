clc;
clear all;

a = [1, 2, 3; 4, 5, 6; 7, 8, 9]

code = "a"
while true
  code = input("Enter r fro rows c for columns: ", 's');
  if code == "r" || code == "c"
    break;
  end
end

x = 0;
y = 0;

while true
  x = input("Enter first index: ");
  if x >= 1 && x <= 3
    break;
  end
  puts("ERROR: Index out of range \n");
end

    
while true
  y = input("Enter second index: ");
  if y >= 1 && y <= 3
    break;
  end
  puts("ERROR: Index out of range \n");
end

puts("Sum= ");
if code == "r"
  a(x, :) + a(y, :)
else
  a(:, x) + a(:, y)
end
