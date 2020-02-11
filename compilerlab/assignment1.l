%{
#include<stdio.h>
%}
%%
[a-zA-Z_]*[+-]?[=][_a-zA-Z0-9]*[+*/-]?[_a-zA-Z0-9]* {
    printf("valid");
}
.* {
    printf("invalid");
}
%%
int yywrap()
{
    return 1;
}
int main()
{
    printf("enter an expression : ");
    yylex();
    return 0;
}