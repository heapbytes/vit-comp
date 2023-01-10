#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct stack {
  char items[25];
  int top;
} stack;

void push(stack *s, char c) {
  s->items[++s->top] = c;
}

char pop(stack *s) {
  return s->items[s->top--];
}

char peek(stack *s) {
  return s->items[s->top];
}

int is_empty(stack *s) {
  return s->top == -1;
}

int is_operand(char c) {
  return isalpha(c);
}

int precedence(char c) {
  if (c == '+' || c == '-') {
    return 1;
  } else if (c == '*' || c == '/') {
    return 2;
  } else if (c == '^') {
    return 3;
  }
  return 0;
}

void infix_to_prefix(char infix[], char prefix[]) {
  stack s;
  s.top = -1;

  int i, j;
  int len = strlen(infix);
  for (i = len - 1, j = 0; i >= 0; i--) {
    if (is_operand(infix[i])) {
      prefix[j++] = infix[i];
    } else {
      while (!is_empty(&s) && precedence(peek(&s)) > precedence(infix[i])) {
        prefix[j++] = pop(&s);
      }
      push(&s, infix[i]);
    }
  }

  while (!is_empty(&s)) {
    prefix[j++] = pop(&s);
  }
  prefix[j] = '\0';
}

int main() {
  char infix[] = "A*B+C*D";
  char prefix[25];

  infix_to_prefix(infix, prefix);
  printf("Infix Expression: %s\n", infix);
  printf("Prefix Expression: %s\n", strrev(prefix));

  return 0;
}

