#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int i=0,j=0,n;
	char expr[20],exprcpy[20];

	printf("Enter an Expression - ");
	gets(exprcpy);
	

	while(exprcpy[i] != '\0')    
    	{
        	if(exprcpy[i] != ' ')  
        	{
        	    expr[j++] = exprcpy[i];
        	}
        	
        	i++;
    	}	
    	expr[j] = '\0';

	n = strlen(expr);

	for(i=0;i<n;i++)
	{
		if(((expr[i]>='a')&&(expr[i]<='z'))||((expr[i]>='A')&&(expr[i]<='Z')))
		{
			if(isalnum(expr[i+1]))
			{
				printf(" %c%c is an operand\n",expr[i],expr[i+1]);
				i=i+1;
			}
			else
				printf(" %c is an alphabetic operand\n",expr[i]);
		}
		
		else if(expr[i]>='0' && expr[i]<='9')
			printf(" %c is a numeric value\n",expr[i]);

		else if(expr[i]=='=')
		{
			if(expr[i+1]=='>' || expr[i+1]=='<' || expr[i+1]=='=')
			{
				printf(" %c%c is a relational operator\n",expr[i],expr[i+1]);
				i=i+1;
			}
			else
				printf(" %c is an assignment operator\n",expr[i]);
		}
		
		else if(expr[i]=='>'||expr[i]=='<')
			printf(" %c is a relational operator\n",expr[i]);

		else if(expr[i]=='!')
		{
			if(expr[i+1]=='=')
			{
				printf(" %c%c is a relational operator\n",expr[i],expr[i+1]);
				i=i+1;
			}
			else
			{
				printf(" %c is a logical operator\n",expr[i]);
			}		
		}


		else if(expr[i]=='^' || expr[i]=='%' || expr[i]=='/' || expr[i]=='*')
		{
			if(expr[i+1]=='=')
			{
				printf(" %c%c is an assignment operator\n",expr[i],expr[i+1]);
				i=i+1;
			}
			else
			{
				printf(" %c is a binary(arithmetic) operator\n",expr[i]);
			}
		}

		else if(expr[i]=='+')
		{
			if(expr[i+1]=='+')
			{
				printf(" %c%c is an unary (incremental) operator\n",expr[i],expr[i+1]);
				i=i+1;
			}
			else if(expr[i+1]=='=')
			{
				printf(" %c%c is an assignment operator\n",expr[i],expr[i+1]);
				i=i+1;
			}
			else
			{
				printf(" %c is a binary (arithmetic) operator\n",expr[i]);
			}		
		}

		else if(expr[i]=='-')
		{
			if(expr[i+1]=='-')
			{
				printf(" %c%c is a unary (decremental) operator\n",expr[i],expr[i+1]);
				i=i+1;
			}
			else if(expr[i+1]=='=')
			{
				printf(" %c%c is an assignment operator\n",expr[i],expr[i+1]);
				i=i+1;
			}
			else if(isalnum(expr[i-1])&&isalnum(expr[i+1]))
			{
				printf(" %c is a binary (arithmetic) operator\n",expr[i]);
			}			
			else
			{	
				printf(" %c is an unary operator\n",expr[i]);
			}
		}

		else if(expr[i]=='(' || expr[i]==')')
			printf(" %c is a curved bracket\n",expr[i]);

		else if(expr[i]=='{' || expr[i]=='}')
			printf(" %c is a curly brace\n",expr[i]);

		else if(expr[i]=='[' || expr[i]==']')
			printf(" %c is a boxed bracket\n",expr[i]);

		else if(expr[i]==' ')
			continue;

	}
}		
