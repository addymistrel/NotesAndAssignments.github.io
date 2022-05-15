//Program to convert triplet form to sparse matrix
#include <stdio.h>
void input(int[][3]);
void sparse(int[][3],int[][20]);
void display(int[][3]);
int main()
{
	int t[20][3],sp[20][20];
	printf("Enter the number of rows of the original sparse matrix = ");
	scanf("%d",&t[0][0]);
	printf("Enter the number of columns of the original sparse matrix = ");
	scanf("%d",&t[0][1]);
	printf("Enter the number of non zero elememts in the original sparse matrix = ");
	scanf("%d",&t[0][2]);
	printf("Enter the remaining non-zero elements of the original sparse matrix:\n");
	input(t);
	printf("\nGiven Triplet form of original Sparse Matrix is:\n");
	display(t);
	printf("\n\n");
	printf("Original Sparse matrix is:\n");
	sparse(t,sp);
	return 0;
}
void input(int x[][3])
{
	int i;
	for(i=1;i<x[0][2]+1;i++)
	{
		printf("%d. Enter row number = ",i);
		scanf("%d",&x[i][0]);
		printf("   Enter column number = ");
		scanf("%d",&x[i][1]);
		printf("   Enter the non zero element = ");
		scanf("%d",&x[i][2]);
		printf("\n");
	}

}
void display(int x[][3])
{
	int i;
	for(i=0;i<x[0][2]+1;i++)
	printf("%d\t%d\t%d\n",x[i][0],x[i][1],x[i][2]);
	printf("\n");
}
void sparse(int s[][3],int t[][20])
{
	int i,j,k=1;
	for(i=0;i<s[0][0];i++)
		for(j=0;j<s[0][1];j++)
		t[i][j]=0;
	for(i=1;i<=s[0][2];i++)
	t[s[i][0]][s[i][1]]=s[i][2];
	//Displaying Sparse matrix
	for(i=0;i<s[0][0];i++)
	{
		for(j=0;j<s[0][1];j++)
		printf("%d\t",t[i][j]);
		printf("\n");
	}
	printf("\n");
}
