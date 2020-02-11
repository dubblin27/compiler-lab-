%{
    char* scope();
    int flag=0;
    int gflag=0;
%}
%%
(main)|(return) {

}
['][a-z][']|[=][a-z] {

}
[;,#<>.() \n] {

}
[{] {
    gflag=1;
}
[}] {
    gflag=0;
}
[0-9=]  {

}
(int) {
    flag=1;
}
(float) {
    flag=2;
}
(char) {
    flag=3;
}
(double) {
    flag=4;
}
[a-z]+ {
    switch(flag)
    {
        case 1:printf("%s\t\t%s\t%ld\t%s\n",yytext,"int",sizeof(int),scope());break;
        case 2:printf("%s\t\t%s\t%ld\t%s\n",yytext,"float",sizeof(float),scope());break;
        case 3:printf("%s\t\t%s\t%ld\t%s\n",yytext,"char",sizeof(char),scope());break;
        case 4:printf("%s\t\t%s\t%ld\t%s\n",yytext,"double",sizeof(double),scope());break;
    }
}
%%
int yywrap()
{
    return 1;
}
char* scope()
{
    if(gflag==1)
        return "local";
    else return "global";
}
int main()
{
    FILE* fptr;
    fptr = fopen("tempfile.c","r");
    yyin = fptr;
    printf("identifier\ttype\tsize\tscope\n");
    printf("-------------------------------------\n");
    yylex();
    return 0;
}
