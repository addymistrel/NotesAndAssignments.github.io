//Program to convert a sparse matrix into its triplet form
#include <stdio.h>
void input(int[][20],int,int);
void triplet(int[][20],int[][20],int,int);
void display(int[][20],int,int);
int main()
{
	int sp[20][20],t[20][20],r,c;
	printf("Enter the number of rows and columns of the sparse matrix:\n");
	scanf("%d%d",&r,&c);
	printf("Enter the elements of the sparse matrix:\n");
	input(sp,r,c);
	triplet(sp,t,r,c);
	printf("\nGiven Sparse Matrix is:\n");
	display(sp,r,c);
	printf("\n\n");
	printf("Triplet form is:\n");
	display(t,t[0][2]+1,3);
	return 0;
}
void input(int x[][20],int r,int c)
{
	int i,j,k=0;
	for(i=0;i<r;i++)
	for(j=0;j<c;j++)
	{
		printf("Element number %d = ",++k);
		scanf("%d",&x[i][j]);
	}
}
void display(int x[][20],int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		printf("%d\t",x[i][j]);
		printf("\n");
	}
	printf("\n");
}
void triplet(int s[][20],int t[][20],int r,int c)
{
	int i,j,k=1;
	t[0][0]=r;
	t[0][1]=c;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(s[i][j]!=0)
			{
				t[k][0]=i;
				t[k][1]=j;
				t[k][2]=s[i][j];
				k++;
			}
		}
	}
	k--;
	t[0][2]=k;
}
