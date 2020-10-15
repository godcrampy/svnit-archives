function [r c] = search(matrix, string)
  [R C] = size(matrix);
  r = 0;
  c = 0;
  for i = 1:R
    for j = 1:C
      if matrix(i, j) == string
        r = i;
        c = j;
        break
      end
    end
  end
end
