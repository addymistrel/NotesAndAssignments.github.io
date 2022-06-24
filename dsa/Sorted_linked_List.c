//Linked List Program to create a sorted linked list and implement insert and delete function
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
node *start=NULL;

//Sorted Create Function

void sort_create()
{
	node *new,*temp,*t1;
	char ch;
	do
	{
		temp=start;
		if((new=(node*)malloc(sizeof(node)))==NULL)
		{
			printf("Memory allocation Unsuccessfull!!!\n");
			return;
		}
		printf("Enter the element to insert = ");
		scanf("%d",&new->data);
		if(start==NULL)
		{
			start=new;
			new->next=NULL;
		}
		else
		{
			while((temp!=NULL)&&(new->data>temp->data))
			{
				t1=temp;
				temp=temp->next;
			}
			t1->next=new;
			new->next=temp;
		}
		printf("\n1. Enter y to continue inserting into the list.\n");
		printf("2. Else Enter any key to exit creating of the list.\n");
		printf("\nYour choice --> ");
		scanf(" %c",&ch);
	}
	while(ch=='y' || ch=='Y');
}

//Delete Function

void display()
{
	node *temp=start;
	if(temp==NULL)
	{
		printf("List is Empty!!!\n");
		return;
	}
	printf("\nNow the Linked List Contains:\n");
	while(temp!=NULL)
	{
		printf("%d  ",temp->data);
		temp=temp->next;
	}
	printf("\n\n");
}

//Sorted Insert Function

void insert()
{
	node *t1,*temp,*new;
	temp=start;
	if((new=(node *)malloc(sizeof(node)))==NULL)
	{
		printf("Memory allocation Unsuccessfull!!!\n");
		return;
	}
	printf("Enter the element to Insert = ");
	scanf("%d",&new->data);
	while((temp!=NULL)&&(new->data>temp->data))
	{
		t1=temp;
		temp=temp->next;
	}
	new->next=t1->next;
	t1->next=new;
	printf("\nElement Successfully inserted :)\n");
}

//Sorted Delete Function

void delete()
{
	node *t1,*temp;
	int ele;
	temp=start;
	printf("Enter the element to Delete = ");
	scanf("%d",&ele);
	if(start->data==ele)
	{
		start=start->next;
	}
	else
	{
		while((temp!=NULL)&&(temp->data<ele))
		{
			t1=temp;
			temp=temp->next;
		}
		if((temp->data!=ele)||(temp==NULL))
		{
			printf("Element not Found!!!\n");
			return;
		}
		t1->next=temp->next;
	}
	free(temp);
	printf("\nDeletion Successfull :)\n\n");
}

//MAIN Function

int main()
{
	int choice;
	printf("\nCreating a Linked List ... \n");
	sort_create();
	printf("\nLinked List Successfully Created :)\n");
	while(1)
	{
read:
		printf("\n1. Press 1 to Insert an element.\n");
		printf("2. Press 2 to Delete an element.\n");
		printf("3. Press 3 to Display the Linked List.\n");
		printf("4. Press 4 to EXIT.\n");
		printf("\nYour choice --> ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert();
				break;
			case 2:
				delete();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("\nTHANK YOU for choosing My Program\nHAVE A NICE DAY :)\n\n");
				exit(0);
			default:
				printf("Wrong Choice Entered\nPlease Enter the Correct Choice.\n");
				goto read;
		}
	}
	return 0;
}
