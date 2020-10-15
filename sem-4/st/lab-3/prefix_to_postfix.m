function res = prefix_to_postfix(prefix)
  stack = {};
  postfix = '';
  for i = 1:length(prefix)
    token = prefix(length(prefix) - i + 1);
    if is_operator(token)
      a = top(stack);
      stack = pop(stack);
      b = top(stack);
      stack = pop(stack);
      temp = [a  b  token];
      stack = push(stack, temp);
    else
      stack = push(stack, token);
    end
  end
  res = char(stack);
end

function bool = is_operator(a)
  if a == '+' || a == '-' || a == 'x' || a == '/' || a == '^' || a == '*'
    bool = true;
  else
    bool = false;
  end
end

function stack = pop(stack)
  if !empty(stack)
    stack = stack(1: end - 1);
  end
end

function stack = push(stack, n)
  stack = [stack n];
end

function n = top(stack)
  n = stack(end);
  n = char(n);
end

function bool = empty(stack)
  bool = length(stack) == 0;
end