//Menu Driven Program to perform various operations On a circular queue using structure.
/*Created by Aditya
  Dated 10th May 2022
  Editor- VI Unix
 */
#define size 6
#include <stdio.h>
#include <stdlib.h>
typedef struct queue
{
	int q[size];
	int front;
	int rear;
}que;
void insert(que *queue,int ele)
{
	if(queue->front==(queue->rear+1)%size)
	{
		printf("\nQueue is Full!!!\n\n");
		return;
	}
	if(queue->front==-1)
	{
		queue->front++;
		queue->rear++;
	}
	else
	queue->rear=(queue->rear+1)%size;
	queue->q[queue->rear]=ele;
	printf("\nElement is Inserted :)\n\n");
}
int delete(que *queue)
{
	int value;
	if(queue->front==-1)
	{
		printf("\nQueue is Empty!!!\n\n");
		exit(0);
	}
	value=queue->q[queue->front];
	if(queue->front==queue->rear)
	queue->front=queue->rear=-1;
	else
	queue->front=(queue->front+1)%size;
	return value;
}
void display(que *queue)
{
	int i;
	if(queue->front==-1)
	{
		printf("\nQueue is Empty!!!\n\n");
		return;
	}
	if(queue->front<=queue->rear)
	{
		for(i=queue->front;i<=queue->rear;i++)
		printf("%d  ",queue->q[i]);
		printf("\n");
	}
	else
	{
		for(i=queue->front;i<size;i++)
		printf("%d  ",queue->q[i]);
		for(i=0;i<=queue->rear;i++)
		printf("%d  ",queue->q[i]);
		printf("\n");
	}
}

//MAIN FUNCTION
int main()
{
	int element,choice;
	que queue;
	queue.front=queue.rear=-1;
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
				insert(&queue,element);
				break;
			case 2:
				element=delete(&queue);
				printf("\nDeleted Element is = %d\n",element);
				break;
			case 3:
				printf("\nNow the Queue Contains :=\n");
				display(&queue);
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
				
