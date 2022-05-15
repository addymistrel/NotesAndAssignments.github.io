#include <stdio.h>
void input(int[],int);
void sel_sort(int[],int);
void display(int[],int);
int main()
{
	int n,ctr;
	printf("Enter the total number of elements = ");
	scanf("%d",&n);
	int a[n];
	input(a,n);
	printf("\nBefore sorting array:\n");
	display(a,n);
	sel_sort(a,n);
	return 0;
}
void input(int x[],int l)
{
	int i;
	printf("Enter the elements of the array:\n");
	for(i=0;i<l;i++)
	{
		printf("Element number %d = ",i+1);
		scanf("%d",&x[i]);
	}
}
void sel_sort(int x[],int l)
{
	int i,j,temp,min_index;
	for(i=0;i<l;i++)
	{
		min_index=i;
		for(j=i+1;j<l;j++)
		{
			if(x[j]<x[min_index])
				min_index=j;
		}
		temp=x[i];
		x[i]=x[min_index];
		x[min_index]=temp;
	}
	printf("\nSorted array is:\n");
	display(x,l);
}
void display(int x[],int l)
{
	int i;
	for(i=0;i<l;i++)
		printf("%d ",x[i]);
	printf("\n");
}
