//FLEXCODE

%{
#include <stdio.h>
%}

%%
"int"|"float"|"char"|"return" { printf("Keyword: %s\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]*       { printf("Identifier: %s\n", yytext); }
[0-9]+                       { printf("Number: %s\n", yytext); }
[\+\-\*/\=\<\>\!\&\|\;\,\(\)\{\}] { printf("Special Character: %s\n", yytext); }
\n                           { /* Ignore newlines */ }
[ \t]                        { /* Ignore whitespace */ }
.                            { printf("Unknown: %s\n", yytext); }
%%

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            perror("Unable to open file");
            return 1;
        }
        yyin = file;
    }
    yylex();
    return 0;
}

//SAVE CODE TO lexer.l

//GENERATE C CODE USING CODE BELOW

flex lexer.l

//COMPILE GENERATED FILE USING GCC

gcc lex.yy.c -o lexer

//RUN THE PROGRAM WITH AN INPUT FILE

./lexer inputfile.c


