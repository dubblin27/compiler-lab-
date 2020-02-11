%{
#include<stdio.h>
#include<ctype.h>
int c;
%}
op "++"|"--"
rop "<"|">"|"<="|">="|"=="|"!="
id [a-zA-Z][a-zA-Z0-9]*
no [0-9]*
pp [\n\t" "]

%%

for\({id}=({no}|{id})\)?(=,{id}=({no}|{id}))*\;({id}{rop}({id}|{no}))?\;({id}{op})?((,{id}{op})*\)\;?{pp}*\("{"(.*\n)*.*"}") 

    { 
        printf("correct");
        c=0;
}
.* {
    printf("\nwrong");
}
%%
int main()
{ 
    printf("enter for - ");
    yylex();
}
int yywrap()
{
    return 1;
}