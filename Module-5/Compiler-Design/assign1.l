%{
#include <stdio.h>
#include <string.h>

int count = 0;
%}

%%

([a-zA-Z0-9])* {count ++;}

"\n" {
  printf("number of identifiers = %d\n", count);
  count = 0;
}

%%

int yywrap(void){}
int main(void) {
    yylex();

    return 0;
}
