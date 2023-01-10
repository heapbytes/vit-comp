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

void PostfixToInfix()
{
    int n, i, j = 0;
    char a, b, op, x[20];
    printf("Enter the postfix expression\n");
    fflush(stdin);
    gets(str);
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

void PrefixToInfix()
{
    int n, i;
    char a, b, op;
    printf("Enter the prefix expression\n");
    fflush(stdin);
    gets(str);
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
            op = pop();
            a = str[i];
            printf("%c%c", a, op);
        }
    }
    printf("%c\n", str[top--]);
}

void main()
{
    int ch;
    
    printf("What operation do you want to perform: \n");
    
    while (1)
    {
        printf("1.Prefix to Infix   2.Postfix to Infix   3.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        
        case 1:
        {
            PrefixToInfix();
            break;
        }
        
        case 2:
        {
            PostfixToInfix();
            break;
        }
        
        case 3:
        {
            exit(0);
            break;
        }
        
        default:
            printf("Invalid chioce\n");
        
        }
    }
}
