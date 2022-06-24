//Linked List Program to create two Linked List and Merging the two Linked List
/*Created By Aditya
  Dated 31st May 2022
  Editor- VI UniX
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct  node
{
	int data;
	struct node *next;
}node;
node *start1=NULL,*start2=NULL;

//Create Function

void create(node *start)
{
	node *new,*curr;
	char ch;
	do
	{
		if((new=(node*)malloc(sizeof(node)))==NULL)
		{
			printf("Memory allocation Unsuccessfull!!!\n");
			return;
		}
		printf("Enter the element to insert = ");
		scanf("%d",&new->data);
		new->next=NULL;
		if(start==NULL)
		{
			start=new;
			curr=new;
		}
		else
		{
			curr->next=new;
			curr=new;
		}
		printf("\n1. Enter y to continue inserting into the list.\n");
		printf("2. Else Enter any key to exit creating of the list.\n");
		printf("\nYour choice --> ");
		scanf(" %c",&ch);
	}
	while(ch=='y' || ch=='Y');
}

//Display Function

void display(node *start)
{
	node *temp=start;
	if(temp==NULL)
	{
		printf("List is Empty!!!\n");
		return;
	}
	while(temp!=NULL)
	{
		printf("%d  ",temp->data);
		temp=temp->next;
	}
	printf("\n\n");
}

//Merge Function

void merge(node *start1,*start2)
{
	node *temp=start1;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=start2;
}

//MAIN Function

int main()
{
	printf("\nCreating 1st Linked List...\n\n");
	create(start1);
	printf("\nSuccessfully Created 1st Linked List :)\n");

	printf("\nCreating 2nd Linked List...\n\n");
	create(start2);
	printf("Successfull Created 2nd Linked List :)\n");

	printf("1st Linked List Contains -->\n");
	display(start1);

	printf("\n2nd Linked List Contains -->\n");
	display(start2);
	
	void merge(start1,start2);
	printf("After Merging Now the Linked List is -->\n");
	display(start1);

	printf("Thank You For Choosing My Progra :)\nHAVE A NICE DAY.\n\n");
	return 0;
}	
