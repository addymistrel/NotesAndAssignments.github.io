//Postfix Evaluation
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
	printf("Enter a valid Postfix Expression:\n");
	scanf("%s",post);
	eval=eval_postfix(post);
	printf("\nValue of the given Postfix Expression = %d\n",eval);
	return 0;
}