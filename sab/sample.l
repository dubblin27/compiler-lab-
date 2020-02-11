%{
#include<stdio.h>

%}
%%
"while"|"if"|"for"|"do"|"else"|"int"|"char"|"double"|"float"|"ll"|"string" {
     printf("%s is a keyword", yytext);

}

[a-zA-Z0-9_]* {
    printf("%s is anidentifiers",yytext);
}
%%
int yywrap(){return 1;}
int main(){
    printf("enter an identifier : ");
    yylex();
    return 0 ;
}