%{
	#include<stdio.h>
%}

%%

"while"|"if"|"for"|"else"|"int"|"float"|"double"|"char" {printf("%s is  Keyword \n",yytext);}

[a-zA-Z_][a-zA-Z0-9_]* {printf("%s is an Identifier \n",yytext);}

"+"|"-"|"*"|"/"|"^" {printf("%s is a Binary Operator \n",yytext);}

"++" {printf("%s is an Incremental Operator \n",yytext);}

"--" {printf("%s is a Decremental Operator \n",yytext);}

"=="|"<="|">="|"<"|">"|"!=" {printf("%s is a Relational Operator \n",yytext);}

"="|"=+"|"=-"|"=*"|"=/"  {printf("%s is an Assignment Operator\n",yytext);}

[0-9]+ {printf("%s is an Integer \n",yytext);}

[0-9]*"."[0-9]+ {printf("%s is a Float \n",yytext);}

";" {printf("%s is a Semicolon\n",yytext);}

[,] {printf("%s is a Seperator \n",yytext);}

" " {printf("(space)\n",yytext);}

"("|")" {printf("%s is a Curved Bracket \n",yytext);}

"{"|"}" {printf("%s is a Curly Brace \n",yytext);}

"["|"]" {printf("%s is a Box Bracket \n",yytext);}

%%

int yywrap()								
{
	return 1;
}

int main()
{
	printf("Enter a String -");
	yylex();
	return 0;
	exit(0);
}

