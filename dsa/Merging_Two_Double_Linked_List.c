//Linked List Program to create two Double Linked List and Merging the two Double Linked List into third
/*Created By Aditya
  Dated 7th June 2022
  Editor- VI UniX
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct  node
{
	int data;
	struct node *next;
	struct node *prev;
}node;

//Create Function

node * create()
{
	node *start=NULL,*new,*curr;
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
			start->prev=NULL;
			curr=new;
		}
		else
		{
			curr->next=new;
			new->prev=curr;
			curr=new;
		}
		printf("\n1. Enter y to continue inserting into the list.\n");
		printf("2. Else Enter any key to exit creating of the list.\n");
		printf("\nYour choice --> ");
		scanf(" %c",&ch);
	}
	while(ch=='y' || ch=='Y');
	return start;
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

void merge(node *start1,node *start2)
{
	node *temp=start1;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=start2;
	start2->prev=temp;
}

//MAIN Function

int main()
{
	node *start1=NULL,*start2=NULL;
	printf("\nCreating 1st Double Linked List...\n\n");
	start1=create();
	printf("\nSuccessfully Created 1st Double Linked List :)\n");

	printf("\nCreating 2nd Double Linked List...\n\n");
	start2=create();
	printf("\nSuccessfull Created 2nd Double Linked List :)\n");

	printf("\n1st Double Linked List Contains -->\n");
	display(start1);

	printf("\n2nd Double Linked List Contains -->\n");
	display(start2);
	
	merge(start1,start2);
	printf("Merged Double Linked List is -->\n");
	display(start1);

	printf("Thank You For Choosing My Program :)\nHAVE A NICE DAY.\n\n");
	return 0;
}	
