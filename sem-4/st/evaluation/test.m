function test(n)
  for i = 1:n
    byTwo = ~rem(i, 2);
    byFive = ~rem(i, 5);
    printf("Testing %d: ", i);
    if byTwo & byFive
      puts("Divisible by two and five\n");
    elseif byTwo
      puts("Divisible by two only\n");
    elseif byFive
      puts("Divisible by five only\n");
    else
      puts("Not Divisible by two or five\n");
    end
  end
end
