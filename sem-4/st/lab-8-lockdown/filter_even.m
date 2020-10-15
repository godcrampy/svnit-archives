function even_vector = filter_even(arr)
  even_vector = [];
  for i = 1:length(arr)
    if ~rem(arr(i), 2)
      even_vector = [even_vector arr(i)];
    end
  end
end