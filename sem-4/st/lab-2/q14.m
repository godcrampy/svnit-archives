clc;
clear all;

a = [4, 9, 2; 3, 5, 7; 8, 1, 6];

[n_r, n_c] = size(a);

if n_r ~= n_c
  puts("Not a square matrix\n");
  return
endif

s = sum(a(1, :));

for i = 1:n_c
  if s ~= sum(a(i, :)) || s ~= sum(a(:, i))
    puts("Not a magic square\n");
    return;
  endif
endfor

if s ~= trace((a)) || s ~= trace(flip(a))
      puts("Not a magic square\n");
      return;
endif

puts("Magic Square!\n");
