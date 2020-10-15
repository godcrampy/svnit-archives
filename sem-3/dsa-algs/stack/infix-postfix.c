#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_MAX 100

typedef struct stack {
  char arr[STACK_MAX];
  int top;
} stack;

stack* new_stack();
void push(stack* s, char data);
char pop(stack* s);
char* infix_to_postfix(char* input);
int validate_infix(char* input);
int evaluate_postfix(char* postfix);

int main(int argc, char const* argv[]) {
  char input[100];
  input[0] = '(';
  fgets(input + 1, 100, stdin);
  int itr = 0;
  while (input[itr] != '\n') {
    ++itr;
  }
  input[itr] = ')';
  if (validate_infix(input)) {
    printf("%s\n", infix_to_postfix(input));
    printf("%d\n", evaluate_postfix(infix_to_postfix(input)));
  } else {
    printf("Invalid Infix\n");
  }
  return 0;
}

stack* new_stack() {
  stack* final = (stack*)malloc(sizeof(stack));
  final->top = -1;
  return final;
}

void push(stack* s, char data) {
  ++s->top;
  s->arr[s->top] = data;
}

char pop(stack* s) {
  int final = s->arr[s->top];
  --s->top;
  return final;
}

int _mathcing_paren(char a, char b) {
  if (a == '(' && b == ')') {
    return 1;
  }
  if (a == '[' && b == ']') {
    return 1;
  }
  if (a == '{' && b == '}') {
    return 1;
  }
  return 0;
}

int precedence(char a) {
  switch (a) {
    case '^':
      return 4;
    case '*':
    case '/':
      return 3;
    case '+':
    case '-':
      return 2;
    default:
      return 1;
  }
}

char* infix_to_postfix(char* input) {
  char* postfix = (char*)malloc(sizeof(char) * 100);
  int next_empty_position = 0;
  int itr = 0;
  stack* s = new_stack();
  while (input[itr] != '\0') {
    char ch = input[itr];
    if (ch == '(' || ch == '[' || ch == '{') {
      push(s, ch);
    } else if (ch == ')' || ch == ']' || ch == '}') {
      while (!_mathcing_paren(s->arr[s->top], ch)) {
        postfix[next_empty_position] = pop(s);
        ++next_empty_position;
      }
      pop(s);
    } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
      while (precedence(s->arr[s->top]) >= precedence(ch)) {
        postfix[next_empty_position] = pop(s);
        ++next_empty_position;
      }
      push(s, ch);
    } else {
      postfix[next_empty_position] = ch;
      ++next_empty_position;
    }
    ++itr;
  }
  postfix[next_empty_position] = '\0';
  return postfix;
}

int validate_infix(char* input) {
  stack* s = new_stack();
  int itr = 0;
  while (input[itr] != '\0') {
    char ch = input[itr];
    if (ch == '(' || ch == '[' || ch == '{') {
      push(s, ch);
    }
    if (ch == ')' || ch == ']' || ch == '}') {
      if (_mathcing_paren(s->arr[s->top], ch)) {
        pop(s);
      } else {
        return 0;
      }
    }
    ++itr;
  }
  if (s->top == -1) {
    return 1;
  }
  return 0;
}

int _power(int a, int b) {
  int res = 1;
  while (b >= 1) {
    res *= a;
    --b;
  }
  return res;
}

int evaluate_postfix(char* postfix) {
  stack* s = new_stack();
  int itr = 0;
  while (postfix[itr] != '\0') {
    char c = postfix[itr];
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
      int a = pop(s);
      int b = pop(s);
      switch (c) {
        case '+':
          push(s, a + b);
          break;
        case '-':
          push(s, a - b);
          break;
        case '*':
          push(s, a * b);
          break;
        case '/':
          push(s, a / b);
          break;
        default:
          push(s, _power(b, a));
          break;
      }
    } else {
      push(s, c - '0');
    }
    ++itr;
  }
  return s->arr[s->top];
}
