//Menu Driven Program for Double Linked List
/*Created By Aditya
  Dated 7th June 2022
  Editor- VI Unix
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
}node;
node *start=NULL;
void insert_first(void)
{
	int ele;
	node *new;
	printf("Enter the element to be inserted = ");
	scanf("%d",&ele);
	if((new=(node*)malloc(sizeof(node)))==NULL)
	{
		printf("Memory Allocation fails!!!\n");
		return;
	}
	new->data=ele;
	new->next=start;
	new->prev=NULL;
	start=new;
	printf("Insertion Successfull\n\n");
}
void insert_last(void)
{
	int ele;
	node *new,*t=start;
	printf("Enter the element to be inserted = ");
	scanf("%d",&ele);
	if((new=(node*)malloc(sizeof(node)))==NULL)
	{
		printf("Memory Allocation Fails!!!\n");
		return;
	}
	new->data=ele;
	new->next=NULL;
	if(start==NULL)
	{
		start=new;
		new->prev=NULL;
	}
	else
	{
		while(t->next!=NULL)
			t=t->next;
		t->next=new;
		new->prev=t;
	}
	printf("Insertion Successful!!!\n\n");
}
void insert_after(void)
{
	node *new,*t=start;
	int ele,ele2;
	printf("Enter the element to be inseted = ");
	scanf("%d",&ele);
	printf("Enter the element after which the element to be inserted = ");
	scanf("%d",&ele2);
	while(t!=NULL && t->data!=ele2)
		t=t->next;
	if(t==NULL)
	{
		printf("Element not found!!!\n");
		return;
	}
	if((new=(node*)malloc(sizeof(node)))==NULL)
	{
		printf("Memory Allocation Unsuccessfull!!!\n");
		exit(0);
	}
	new->data=ele;
	new->next=t->next;
	if(t->next!=NULL)
	{
		t->next->prev=new;
	}
	t->next=new;
	new->prev=t;
	printf("Insertion Successfull!!!\n\n");
}
void insert_before(void)
{
	node *new,*t=start;
	int ele,ele2;
	printf("Enter the element to be inserted = ");
	scanf("%d",&ele);
	printf("Enter the element before which the element to be inserted = ");
	scanf("%d",&ele2);
	while(t!=NULL && t->data!=ele2)
	{
		t=t->next;
	}
	if(t==NULL)
	{
		printf("Element not found!!!\n");
		return;
	}
	if((new=(node*)malloc(sizeof(node)))==NULL)
	{
		printf("Memory Allocation Unsuccessfull!!!\n");
		exit(0);
	}
	new->data=ele;
	if(t == start)
	{
		new->next = t;
		new->prev = NULL;
		start->prev = new;
		start = new;
	}
	else
	{
		new->prev=t->prev;
		new->next=t;
		t->prev->next=new;
		t->prev=new;
	}
	printf("Insertion Successfull!!!\n\n");
}
void insert_pos(void)
{
	node *new,*t;
	int pos,ele,i;
	printf("Enter the Element to insert = ");
	scanf("%d",&ele);
	printf("Enter the position to insert = ");
	scanf("%d",&pos);
	if((new=(node *)malloc(sizeof(node)))==NULL)
	{
		printf("Meomory Allocation Unsuccessfull!!!\n");
		return;
	}
	new->data=ele;
	if(pos==1)
	{
		new->next=start;
		new->prev=NULL;
		start->prev=new;
		start=new;
	}
	else
	{
		t=start;
		for(i=1;(t!=NULL)&&(i<pos-1);i++)
		{
			t=t->next;
		}
		if(t==NULL)
		{
			printf("Invalid Insertion!!!\n");
			return;
		}
		new->next=t->next;
		new->prev=t;
		if(t->next!=NULL)
		{
			t->next->prev=new;
		}
		t->next=new;
	}
	printf("Insertion SuccessFull :)");
}

int delete_first(void)
{
	node *t=start;
	if(start==NULL)
	{
		printf("List is Emplty!!!\n\n");
		exit(0);
	}
	int del;
	del=start->data;
	start=start->next;
	start->prev=NULL;
	free(t);
	return del;
}
int delete_last(void)
{
	node *t=start;
	int del;
	if(t==NULL)
	{
		printf("List is Empty!!!\n\n");
		exit(0);
	}
	while(t->next!=NULL)
	{
		t=t->next;
	}
	if(t==start)
	{
		start=NULL;
	}
	else
	{
		t->prev->next=NULL;
	}
	del=t->data;
	free(t);
	return del;
}
int delete_element_pos(void)
{
	node *t=start;
	int del,pos,i;
	printf("Enter the position to be Deleted = ");
	scanf("%d",&pos);
	if(t==NULL)
	{
		printf("List is Empty!!!\n");
		exit(0);
	}
	if(pos==1)
	{
		start=start->next;
		start->prev=NULL;
	}
	else
	{
		for(i=1;(t!=NULL)&&(i<pos);i++)
		{
			t=t->next;
		}
		if(t==NULL)
		{
			printf("Invalid Position!!!\n");
			exit(0);
		}
		t->prev->next=t->next;
		if(t->next!=NULL)
		{
			t->next->prev=t->prev;
		}
	}
	del=t->data;
	free(t);
	return del;
}
void display(void)
{
	node *t=start;
	if(t==NULL)
	{
		printf("Linked List is Empty!!!\n");
		return;
	}
	while(t!=NULL)
	{
		printf("%d ",t->data);
		t=t->next;
	}
	printf("\n\n");
}
int node_count(void)
{
	node *t=start;
	int count=0;
	if(t==NULL)
	{
		return 0;
	}
	while(t!=NULL)
	{
		count++;
		t=t->next;
	}
	return count;
}

//MAIN FUNCTION
int main()
{
	int choice,c,del,sum2,cc;
	while(1)
	{
read:
		printf("\n\nPress 1 for Insertion :--:\n");
		printf("Press 2 for Deletion :--:\n");
		printf("Press 3 to Display The Information Field :--:\n");
		printf("Press 4 to Count the Nodes  :--:\n");
		printf("Press 5 to Exit:--:\n");
		printf("\nYour Choice --> ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
read2:
				printf("\n1. First Position\n2. Last Position\n3. After an Element\n4. Before an Element\n");
				printf("5. At a Specific Position\n");
				printf("Your choice -->> ");
				scanf("%d",&c);
				switch(c)
				{
					case 1:
						insert_first();
						break;
					case 2:
						insert_last();
						break;
					case 3:
						insert_after();
						break;
					case 4:
						insert_before();
						break;
					case 5:
						insert_pos();
						break;
					default:
						printf("Wrong Choice Entered!!!\n");
						goto read2;
				}
				break;
			case 2:
read3:
				printf("1. First Position\n2. Last Position\n3. Particular Position\n");
				printf("Your Choice -->> ");
				scanf("%d",&c);
				switch(c)
				{
					case 1:
						del=delete_first();
						printf("Deleted Element = %d\n\n",del);
						break;
					case 2:
						del=delete_last();
						printf("Deleted Element = %d\n\n",del);
						break;
					case 3:
						del=delete_element_pos();
						printf("Deleted Element = %d\n\n",del);
						break;
					default:
						printf("Wrong Choice Entered!!!\n\n");
						goto read3;
				}
				break;
			case 3:
				printf("\nNow the Linked List Contains:\n");
				display();
				break;
			case 4:
				cc=node_count();
				printf("Total Number of nodes = %d\n",cc);
				break;
			case 5:
				printf("\nTHANK YOU For Choosing My Program\nHAVE A NICE DAY!!\n");
				exit(0);
			default:
				printf("Wrong Choice Entered!!!\n");
				goto read;
		}
	}
	return 0;
}
