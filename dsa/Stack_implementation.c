//Menu Driven Program on stacks
/*Designed by Aditya
  Dated 26th April 2022
  Editor- VI UNIx
*/
#define size 100
#include <stdio.h>
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
void display(int st[])
{
	int i;
	if(top==-1)
	{
		printf("The stack is empty!!!\n");
		exit(0);
	}
	for(i=top;i>=0;i--)
	printf("%d  ",st[i]);
	printf("\n");
}
int main()
{
	int stack[size],choice,temp;
	top=-1;
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
			push(stack,temp);
			goto read;
		case 2:
			temp=pop(stack);
			printf("Popped element is = %d\n",temp);
			goto read;
		case 3:
			printf("Now the stack contains:\n");
			display(stack);
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
