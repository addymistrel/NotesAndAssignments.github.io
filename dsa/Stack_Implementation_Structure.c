//Menu Driven Program on stacks using structure
/*Designed by Aditya
  Dated 26th April 2022
  Editor- VI UNIx
*/
#define size 100
#include <stdio.h>
#include <stdlib.h>
typedef struct stack
{
	int top;
	int stc[size];
}stk;
void push(stk* s,int element)
{
	if(s->top==size-1)
	{
		printf("Stack overflow!!!\n");
		exit(0);
	}
	s->top+=1;
	s->stc[s->top]=element;
}
int pop(stk* s)
{
	int ret;
	if(s->top==-1)
	{
		printf("Stack Underflow!!!\n");
		exit(0);
	}
	ret=s->stc[s->top];
	s->top-=1;
	return ret;
}
void display(stk* s)
{
	int i;
	if(s->top==-1)
	{
		printf("The stack is empty!!!\n");
		exit(0);
	}
	for(i=s->top;i>=0;i--)
	printf("%d  ",s->stc[i]);
	printf("\n");
}
int main()
{
	stk stack;
	int choice,temp;
	stack.top=-1;
read:
	printf("\nPress 1 to push element in stack.\n");
	printf("Press 2 to pop element from stack.\n");
	printf("Press 3 to display the stack.\n");
	printf("Press 4 to exit.\n");
	printf("\nEnter Your choice---> ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("Enter the element to be pushed = ");
			scanf("%d",&temp);
			push(&stack,temp);
			goto read;
		case 2:
			temp=pop(&stack);
			printf("Popped element is = %d\n",temp);
			goto read;
		case 3:
			printf("Now the stack contains:\n");
			display(&stack);
			goto read;
		case 4:
			goto out;
		default:
			printf("Wrong choice Entered!!!\n");
			goto read;
	}
out:
	printf("Thank You For Choosing My Program!!!\nHave a nice Day :)\n");
	return 0;
}
