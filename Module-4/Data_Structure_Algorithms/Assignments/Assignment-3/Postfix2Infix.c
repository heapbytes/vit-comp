#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20
char str[MAX], stack[MAX];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    return stack[top--];
}

char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

void PostfixToInfix()
{
    int n, i, j = 0;
    char a, b, op, x[20];
    char str[] = "ABC*+";
    printf("postfix expression is:\t%s\n", str);
    strrev(str);
    n = strlen(str);
    for (i = 0; i < MAX; i++)
        stack[i] = '\0';
    printf("Infix expression is:\t");
    for (i = 0; i < n; i++)
    {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            push(str[i]);
        }
        else
        {
            x[j] = str[i];
            j++;
            x[j] = pop();
            j++;
        }
    }
    x[j] = str[top--];
    strrev(x);
    printf("%s\n", x);
}

int main(){
  PostfixToInfix();
  return 0;
}

