%{
#include <stdio.h>
#include <string.h>
#include <ctype.h>
%}


%%

[a-zA-Z] {
  if ((int)yytext[0] >=97 && (int)yytext[0] <= 122) {
    printf("%c", ((int)yytext[0] - 32));
  } 
  else if ((int)yytext[0] >= 65 && (int)yytext[0] <= 90) {
    printf("%c", (int)yytext[0] + 32);
  }
  else{
  printf("%c", yytext[0]);
  }
}


%%


int yywrap(void){}
int main(void) {

    yylex();
    return 0;
}
