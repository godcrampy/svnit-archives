function count = odd_count(arr)
  count = 0;
  for i = 1:length(arr)
    if rem(arr(i), 2)
      count += 1;
    endif
  endfor
endfunction
