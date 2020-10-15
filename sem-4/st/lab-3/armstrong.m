function is_armstrong = armstrong(num)
  is_armstrong = 0;
  sum = 0;
  str = num2str(num);
  for i = 1:length(str)
    sum += str2num(str(i)) ^ length(str);
  end
  if num == sum
    is_armstrong = 1;
  end
end
