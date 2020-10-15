function sum = series(n)
  sum = 0;
  for i = 1:n
    sum +=  factorial(i) / ((i + 1) * (i + 2) * (i + 3));
  end
end
