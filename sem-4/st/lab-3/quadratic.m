function root = quadratic(a, b, c)
  d = 2 * a;
  del = sqrt(b ^ 2 - 4 * a * c);
  root = [(-b + del)/d, (-b - del)/d];
end
