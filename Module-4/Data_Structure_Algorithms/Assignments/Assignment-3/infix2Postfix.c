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

void infix_to_postfix(char infix[], char postfix[]) {
  stack s;
  s.top = -1;

  int i, j;
  int len = strlen(infix);
  for (i = 0, j = 0; i < len; i++) {
    if (is_operand(infix[i])) {
      postfix[j++] = infix[i];
    } else if (infix[i] == '(') {
      push(&s, infix[i]);
    } else if (infix[i] == ')') {
      while (!is_empty(&s) && peek(&s) != '(') {
        postfix[j++] = pop(&s);
      }
      pop(&s);
    } else {
      while (!is_empty(&s) && precedence(peek(&s)) >= precedence(infix[i])) {
        postfix[j++] = pop(&s);
      }
      push(&s, infix[i]);
    }
  }

  while (!is_empty(&s)) {
    postfix[j++] = pop(&s);
  }
  postfix[j] = '\0';
}

int main() {
  char infix[] = "A*B+C*D";
  char postfix[25];

  infix_to_postfix(infix, postfix);
  printf("Infix Expression: %s\n", infix);
  printf("Postfix Expression: %s\n", postfix);

  return 0;
}

