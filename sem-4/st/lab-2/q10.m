clc;
clear all;

a = [1, 2, 2, 4; 5, 7, 7, 8; 9, 10, 7, 10; 13, 6, 7, 16]

for i = 1:4
  for j = 1:4
    for k = 1:4
      for l = 1:4
        if a(i, j) == a(k, l) && (i ~= k || j ~= l)
          a(k, l) = 0;
        end
      end
    end
  end
end

a
