function even = even_index(a)
  even = [];
  for i = 1:length(a)
    if mod(a(i), 2) == 0
      even = [even a(i)];
    end
  end
end
