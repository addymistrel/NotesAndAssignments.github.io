//Bubble Sort
#include <stdio.h>
void input(int[],int);
void sort(int[],int);
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
	sort(a,n);
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
void sort(int x[],int l)
{
	int i,j,temp;
	for(i=0;i<l-1;i++)
		for(j=0;j<l-i-1;j++)
		{
			if(x[j]>x[j+1])
			{
				temp=x[j];
				x[j]=x[j+1];
				x[j+1]=temp;
			}
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
