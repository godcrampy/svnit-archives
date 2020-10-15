function even_vector = filter_even_positions(arr)
  even_vector = [];
  for i = 1:length(arr)
    if ~rem(i, 2)
      even_vector = [even_vector arr(i)];
    end
  end
end