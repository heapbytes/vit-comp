%{
#include <stdio.h>
%}

DIGIT       [0-9]
HEX_DIGIT   [0-9A-Fa-f]

%%
{DIGIT}+    {
                int decimalValue = atoi(yytext);
                char hexRepresentation[20]; // Assuming a maximum length
                int i = 0;

                while (decimalValue > 0) {
                    int remainder = decimalValue % 16;
                    if (remainder < 10) {
                        hexRepresentation[i++] = remainder + '0';
                    } else {
                        hexRepresentation[i++] = remainder - 10 + 'A';
                    }
                    decimalValue /= 16;
                }

                printf("%d in decimal is 0x", atoi(yytext));
                while (i > 0) {
                    putchar(hexRepresentation[--i]);
                }
                putchar('\n');
              }
.           { /* Ignore any other characters */ }
%%

int main() {
    yylex();
    return 0;
}

