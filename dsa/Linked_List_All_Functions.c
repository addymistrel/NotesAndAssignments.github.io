//Menu Driven Program for linked list
/*Created By Aditya
  Dated 17th May 2022
  Editor- VI Unix
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
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
	start=new;
	else
	{
		while(t->next!=NULL)
			t=t->next;
		t->next=new;
	}
	printf("Insertion Successful!!!\n\n");
}
void insert_after(void)
{
	node *new,*t=start;
	if(t==NULL)
	{
		printf("List is Empty\n");
		return;
	}
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
	t->next=new;
	printf("Insertion Successfull!!!\n\n");
}
void insert_before(void)
{
	node *new,*t=start,*t1;
	if(t==NULL)
	{
		printf("List is Empty\n");
		return;
	}
	int ele,ele2;
	printf("Enter the element to be inseted = ");
	scanf("%d",&ele);
	printf("Enter the element after which the element to be inserted = ");
	scanf("%d",&ele2);
	while(t!=NULL && t->data!=ele2)
	{
		t1=t;
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
	new->next=t->next;
	t->next=new;
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
		t->next=new;
	}
}
void insert_after_pos(void)
{
	node *t=start,*new;
	int pos,ele,i;
	if(t==NULL)
	{
		printf("No element is present!!!\n");
		return;
	}
	printf("Enter the element to insert = ");
	scanf("%d",&ele);
	printf("Enter the position after which element to insert = ");
	scanf("%d",&pos);
	if((new=(node *)malloc(sizeof(node)))==NULL)
	{
		printf("Meomory Allocation Unsuccessfull!!!\n");
		return;
	}
	new->data=ele;
	for(i=1;(t!=NULL)&&(i<pos);i++)
	{
		t=t->next;
	}
	if(t==NULL)
	{
		printf("Invalid Insertion!!!\n");
		return;
	}
	new->next=t->next;
	t->next=new;
}
void insert_before_pos(void)
{
	node *t=start,*new;
	int pos,ele,i;
	if(t==NULL)
	{
		printf("No element is present!!!\n");
		return;
	}
	printf("Enter the element to insert = ");
	scanf("%d",&ele);
	printf("Enter the position before which element to insert = ");
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
		start=new;
	}
	else
	{
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
		t->next=new;
	}
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
	free(t);
	return del;
}
int delete_last(void)
{
	node *t1,*t=start;
	int del;
	if(t==NULL)
	{
		printf("List is Empty!!!\n\n");
		exit(0);
	}
	while(t->next!=NULL)
	{
		t1=t;
		t=t->next;
	}
	if(t==start)
	{
		start=NULL;
	}
	else
	{
		t1->next=NULL;
	}
	del=t->data;
	free(t);
	return del;
}
int delete_element(void)
{
	node *t1,*t=start;
	int del,ele;
	printf("Enter the Element to be Deleted = ");
	scanf("%d",&ele);
	if(t==NULL)
	{
		printf("List is Empty!!!\n");
		exit(0);
	}
	while(t!=NULL && t->data!=ele)
	{
		t1=t;
		t=t->next;
	}
	if(t==NULL)
	{
		printf("Element not present!!!\n");
		exit(0);
	}
	if(t==start)
	{
		start=start->next;
	}
	else
	{
		t1->next=t->next;
	}
	del=t->data;
	free(t);
	return del;
}
int delete_element_pos(void)
{
	node *t1,*t=start;
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
	}
	else
	{
		for(i=1;(t!=NULL)&&(i<pos);i++)
		{
			t1=t;
			t=t->next;
		}
		if(t==NULL)
		{
			printf("Invalid Position!!!\n");
			exit(0);
		}
		t1->next=t->next;
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
int list_sum(void)
{
	node *t=start;
	int sum=0;
	if(t==NULL)
	{
		return 0;
	}
	while(t!=NULL)
	{
		sum+=t->data;
		t=t->next;
	}
	return sum;
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
		printf("Press 3 for Counting Nodes :--:\n");
		printf("Press 4 to Calculate Sum  :--:\n");
		printf("Press 5 to Display :--:\n");
		printf("Press 6 to Exit:--:\n");
		printf("\nYour Choice --> ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
read2:
				printf("\n1. First Position\n2. Last Position\n3. After an Element\n4. Before an Element\n5. At a Specific Position\n");
				printf("6. After a given position\n7. Before a Given Position\n");
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
					case 6:
						insert_after_pos();
						break;
					case 7:
						insert_before_pos();
						break;
					default:
						printf("Wrong Choice Entered!!!\n");
						goto read2;
				}
				break;
			case 2:
read3:
				printf("1. First Position\n2. Last Position\n3. Particular Element\n4. Particular Position\n");
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
						del=delete_element();
						printf("Deleted Element = %d\n\n",del);
						break;
					case 4:
						del=delete_element_pos();
						printf("Deleted Element = %d\n\n",del);
						break;
					default:
						printf("Wrong Choice Entered!!!\n\n");
						goto read3;
				}
				break;
			case 3:
				cc=node_count();
				printf("Total Number of nodes = %d\n",cc);
				break;
			case 4:
				sum2=list_sum();
				printf("The Sum of all the Elements in Linked List = %d\n",sum2);
				break;
			case 5:
				printf("Now The Linked List Contains:\n");
				display();
				break;
			case 6:
				printf("\nTHANK YOU For Choosing My Program\nHAVE A NICE DAY!!\n");
				exit(0);
			default:
				printf("Wrong Choice Entered!!!\n");
				goto read;
		}
	}
	return 0;
}
