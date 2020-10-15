function postfix = infix_to_postfix(infix)
  infix = ['(' infix ')'];
  postfix = '';
  stack = {};
  for i = 1:length(infix)
    % postfix
    token = infix(i);
    if is_opening_bracket(token)
      stack = push(stack, token);
    elseif is_closing_bracket(token)
      % while no closing bracket
      while !empty(stack) && is_operator(top(stack))
        postfix = [postfix top(stack)];
        stack = pop(stack);
      end
      if !empty(stack)
        if !are_pairs(top(stack), token)
          error("Infix is invalid");
        else
          stack = pop(stack);
        end
      end
    elseif is_operator(token)
      while !empty(stack) && precedence(top(stack)) >= precedence(token)
        postfix = [postfix top(stack)];
        stack = pop(stack);
      end
      stack = push(stack, token);
    else
      % * Number
      postfix = [postfix token];
    end
  end
end

function p = precedence(operator)
  switch operator
  case '+'
    p = 1;
  case '-'
    p = 1;
  case 'x'
    p = 2;
  case '*'
    p = 2;
  case '/'
    p = 2;
  case '^'
    p = 3;
  otherwise
    p = 0;
  end
end

function bool = is_operator(a)
  if a == '+' || a == '-' || a == 'x' || a == '/' || a == '^' || a == '*'
    bool = true;
  else
    bool = false;
  end
end

function bool = are_pairs(a, b)
  if (a == '[' && b == ']') || (a == '(' && b == ')') || (a == '{' && b == '}')
    bool = true;
  else
    bool = false;
  end
end

function bool = is_bracket(c)
  if c == '(' || c == '[' || c == '{' || c == ')' || c == ']' || c == '}'
    bool = true;
  else
    bool = false;
  end
end

function bool = is_opening_bracket(c)
  if c == '(' || c == '[' || c == '{'
    bool = true;
  else
    bool = false;
  end
end

function bool = is_closing_bracket(c)
  if c == ')' || c == ']' || c == '}'
    bool = true;
  else
    bool = false;
  end
end

function stack = pop(stack)
  if !empty(stack)
    stack = stack(1: end - 1);
  end;
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