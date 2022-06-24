//Menu Driven Program to perform various operations On a circular queue without using % Operator.
/*Created by Aditya
  Dated 10th May 2022
  Editor- VI Unix
 */
#define size 6
#include <stdio.h>
#include <stdlib.h>
int front,rear;
void insert(int q[],int ele)
{
	if((rear==size-1 && front==0) || rear+1==front)
	{
		printf("\nQueue is Full!!!\n\n");
		return;
	}
	if(front==-1)
	{
		front=0;
		rear=0;
	}
	else
	{
		if(rear==size-1 && front!=0)
			rear=0;
		else
			rear++;
	}
	q[rear]=ele;
	printf("\nElement is Inserted :)\n\n");
}
int delete(int q[])
{
	int value;
	if(front==-1)
	{
		printf("\nQueue is Empty!!!\n\n");
		exit(0);
	}
	value=q[front];
	if(front==rear)
		front=rear=-1;
	else
	{
		if(front==size-1)
			front=0;
		else
			front++;
	}
	return value;
}
void display(int q[])
{
	int i;
	if(front==-1)
	{
		printf("\nQueue is Empty!!!\n\n");
		return;
	}
	if(front<=rear)
	{
		for(i=front;i<=rear;i++)
		printf("%d  ",q[i]);
		printf("\n");
	}
	else
	{
		for(i=front;i<size;i++)
		printf("%d  ",q[i]);
		for(i=0;i<=rear;i++)
		printf("%d  ",q[i]);
		printf("\n");
	}
}

//MAIN FUNCTION
int main()
{
	int queue[size],element,choice;
	front=rear=-1;
	printf("\n\n*********WELCOME TO MENU BIASED CIRCULAR QUEUE PROGRAM*********\n");
	while(1)
	{
read:
		printf("\nPress 1 for Inserting an Element in Queue.\n");
		printf("Press 2 for Delete an Element From Queue.\n");
		printf("Press 3 to Display all the elements in the Queue.\n");
		printf("Press 4 to exit.\n");
		printf("\nYour Choice --->> ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter the element to be inserted = ");
				scanf("%d",&element);
				insert(queue,element);
				break;
			case 2:
				element=delete(queue);
				printf("\nDeleted Element is = %d\n",element);
				break;
			case 3:
				printf("\nNow the Queue Contains :=\n");
				display(queue);
				break;
			case 4:
				printf("\nTHANK YOU For Choosing My Program.\n");
				printf("HAVE A NICE DAY :)\n\n");
				exit(0);
			default:
				printf("Wrong Choice Entered!!!\nPlease Enter the correct choice.\n");
				goto read;
		}
	}
	return 0;
}
				
