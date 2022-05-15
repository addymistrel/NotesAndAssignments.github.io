//Various Operations on entered Expression
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
int eval_postfix(char post[])
{
	top=-1;
	int i,result,stack[size],temp,a,b;
	printf("\n");
	for(i=0;post[i]!='\0';i++)
	{
		if(((post[i]>=65 && post[i]<91)||(post[i]>=97 && post[i]<123)))
		{
			printf("Enter the value of the operand %c = ",post[i]);
			scanf("%d",&temp);
			push(stack,temp);
		}
		else
		{
				a=pop(stack);
				b=pop(stack);
			switch(post[i])
			{
				case '+':
					temp=b+a;
					break;
				case '-':
					temp=b-a;
					break;
				case '*':
					temp=b*a;
					break;
				case '/':
					temp=b/a;
					break;
				case '%':
					temp=b%a;
					break;
				case '^':
					temp=pow(b,a);
					break;
				default:
					printf("Given Expression is invalid!!!\n");
					exit(0);
			}
			push(stack,temp);
		}
	}
	result=pop(stack);
	return result;
}
int main()
{
	int choice,eval;
	char inf[100],post[100];
read:
	printf("\nPress 1 for Converting an Infix Expression to Postfix.");
	printf("\nPress 2 for Evaluating a Postfix expression.");
	printf("\nPress 3 for Evaluating a an Infix Expression.");
	printf("\nPress 4 to exit.");
	printf("\n\nYour Choice --->> ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("Enter a valid Infix expression:\n");
			scanf("%s",inf);
			convert_infix(inf,post);
			printf("\nPostfix form of given Expression is:\n%s\n",post);
			goto read;
		case 2:
			printf("Enter a valid Postfix Expression:\n");
			scanf("%s",post);
			eval=eval_postfix(post);
			printf("\nValue of the given Postfix Expression = %d\n",eval);
			goto read;
		case 3:
			printf("Enter a valid Infix expression:\n");
			scanf("%s",inf);
			convert_infix(inf,post);
			eval=eval_postfix(post);
			printf("\nValue of the given Infix Expression = %d\n",eval);
			goto read;
		case 4:
			printf("\nThank You For Choosing my Program\n");
			printf("HAVE A NICE DAY :)\n\n");
			exit(0);
		default:
			printf("Wrong Choice Entered!!!\nPlease Enter the Correct Choice\n");
			goto read;
	}
	return 0;
}
