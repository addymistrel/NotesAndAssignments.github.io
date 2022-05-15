//Program to convert triplet form of a sparse matrix into triplet form of its transopose
#include <stdio.h>
void input(int[][3]);
void trans_triplet(int[][3],int[][3]);
void display(int[][3]);
int main()
{
	int t[20][3],tt[20][3],r,c;
	printf("Enter the number of rows of the original sparse matrix = ");
	scanf("%d",&t[0][0]);
	printf("Enter the number of columns of the original sparse matrix = ");
	scanf("%d",&t[0][1]);
	printf("Enter the number of non zero elememts in the original sparse matrix = ");
	scanf("%d",&t[0][2]);
	printf("Enter the remaining non-zero elements of the original sparse matrix:\n");
	input(t);
	trans_triplet(t,tt);
	printf("\nGiven Triplet form of original Sparse Matrix is:\n");
	display(t);
	printf("\n\n");
	printf("Triplet form of its transpose matrix is:\n");
	display(tt);
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
void trans_triplet(int s[][3],int t[][3])
{
	int i,j,k=1;
	t[0][0]=s[0][1];
	t[0][1]=s[0][0];
	t[0][2]=s[0][2];
	for(i=0;i<s[0][1];i++)
	{
		for(j=1;j<=s[0][2];j++)
		if(i==s[j][1])
		{
			t[k][0]=s[j][1];
			t[k][1]=s[j][0];
			t[k][2]=s[j][2];
			k++;
		}
	}

}
