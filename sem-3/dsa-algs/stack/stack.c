#include <stdio.h>
#include <stdlib.h>

#define STACK_MAX 100

typedef struct stack {
  int arr[STACK_MAX];
  int top;
} stack;

stack* new_stack();
void push(stack* s, int data);
int pop(stack* s);

int main(int argc, char const* argv[]) {
  stack* a = new_stack();
  push(a, 4);
  push(a, 5);
  push(a, 6);
  pop(a);
  printf("%d\n", a->arr[a->top]);
  return 0;
}

stack* new_stack() {
  stack* final = (stack*)malloc(sizeof(stack));
  final->top = -1;
  return final;
}

void push(stack* s, int data) {
  ++s->top;
  s->arr[s->top] = data;
}

int pop(stack* s) {
  int final = s->arr[s->top];
  --s->top;
  return final;
}
