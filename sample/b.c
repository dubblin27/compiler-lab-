#include<stdio.h>
#include<string.h>
int i,l;
char expression[40] ,expression1[40],expression2[40];
char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}
void main()
{
   
    printf("\nEnter the expression");
    scanf("%s",expression);
    l=strlen(expression);
    expression2[0]='\0';
    i=0;
    while(expression[i]!='=')
    {
        i++;
    }
    strncat(expression2,expression,i);
    strrev(expression);
    expression1[0]='\0';
    strncat(expression1,expression,l-(i+1));
    strrev(expression1);
    printf("Three address code : \n temp1=%s \n %s=temp2 \n",expression1,expression2);

}


