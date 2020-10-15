function val = evaluate(postfix)
  stack = {};  
  for i = 1:length(postfix)
    token = postfix(i);
    if is_operator(token)
      a = top(stack);
      stack = pop(stack);
      b = top(stack);
      stack = pop(stack);
      res = compute(b, token, a);
      stack = push(stack, num2str(res));
    else
      stack = push(stack, token);
    end
  end
  val = top(stack);
end

function n = compute(a, op, b)
  switch op
  case '+'
    n = str2num(a) + str2num(b);
  case '-'
    n = str2num(a) - str2num(b);
  case '/'
    n = str2num(a) / str2num(b);
  case '*'
    n = str2num(a) * str2num(b);
  case 'x'
    n = str2num(a) * str2num(b);
  case '^'
    n = str2num(a) ^ str2num(b);
  end
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