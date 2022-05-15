//Infix To Postfix
/*Created By Aditya
  Dated 5th may 2022
  Editor- VI Unix
*/
#define size 100
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int top;
void push(int st[],int element)
{
	if(top==size-1)
	{
		printf("Stack overflow!!!\n");
		exit(0);
	}
	top++;
	st[top]=element;
}
int pop(int st[])
{
	int ret;
	if(top==-1)
	{
		printf("Stack Underflow!!!\n");
		exit(0);
	}
	ret=st[top];
	top--;
	return ret;
}
int precedence(int z)
{
	if(z=='(')
		return 0;

	else if(z=='+' || z=='-')
		return 1;
	else if(z=='*' || z=='/' || z=='%')
		return 2;
	else if(z=='^')
		return 3;
	else
	{
		printf("The expression is not valid!!!\n");
		exit(0);
	}
}
void convert_infix(char inf[], char post[])
{
	top=-1;
	int i=0,j=0,temp1,temp2,stack[size];
	char m;
	while(inf[i]!='\0')
	{
		if((inf[i]>=65 && inf[i]<91)||(inf[i]>=97 && inf[i]<123))
		post[j++]=inf[i];

		else if(inf[i]=='(')
			push(stack,inf[i]);

		else if(inf[i]==')')
		{
			while(stack[top]!='(')
			post[j++]=pop(stack);
			pop(stack);
		}
		else if(inf[i]=='+' || inf[i]=='-' || inf[i]=='*' || inf[i]=='/' || inf[i]=='%' || inf[i]=='^')
		{
			if(top==-1)
			push(stack,inf[i]);
			else
			{
				//Collecting the Precedence value
				temp1=precedence(stack[top]);
				temp2=precedence(inf[i]);
				//Collection Ends
				if(temp1>=temp2)
				{
					while(temp1<temp2)
					post[j++]=pop(stack);
				}
				push(stack,inf[i]);
			}
		}
		i++;
	}
	while(top!=-1)
	{
		m=pop(stack);
		post[j++]=m;
	}
	post[j]='\0';
}
int main()
{
	int choice,eval;
	char inf[100],post[100];
	printf("Enter a valid Infix expression:\n");
	scanf("%s",inf);
	convert_infix(inf,post);
	printf("\nPostfix form of given Expression is:\n%s\n",post);
	return 0;
}