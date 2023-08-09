%{
#include <stdio.h>
#include <string.h>
#include <ctype.h>
%}


%%

[a-zA-Z] {
  if (islower(yytext[0])) {
    printf("%c", toupper(yytext[0]));
  } else if (isupper(yytext[0])) {
    printf("%c", tolower(yytext[0]));
  }
  else{
  printf("%c", yytext[0]);
  }
}
return 0;

%%


int yywrap(void){}
int main(void) {

    yylex();
    return 0;
}
