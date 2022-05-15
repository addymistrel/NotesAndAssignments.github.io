//Program to add twp triplet form to sparse matrix into a sum triplet matrix
#include <stdio.h>
#include <stdlib.h>
void input(int[][3]);
void add_trip(int[][3],int[][3],int [][3]);
void display(int[][3]);
int main()
{
	int t1[20][3],t2[20][3],sum[20][3];
	printf("For Matrix 1:\n");
	printf("Enter the number of rows of the original sparse matrix = ");
	scanf("%d",&t1[0][0]);
	printf("Enter the number of columns of the original sparse matrix = ");
	scanf("%d",&t1[0][1]);
	printf("Enter the number of non zero elememts in the original sparse matrix = ");
	scanf("%d",&t1[0][2]);
	printf("Enter the remaining non-zero elements of the original sparse matrix:\n");
	input(t1);
	printf("\nFor Matrix 2:\n");
	printf("Enter the number of rows of the original sparse matrix = ");
	scanf("%d",&t2[0][0]);
	printf("Enter the number of columns of the original sparse matrix = ");
	scanf("%d",&t2[0][1]);
	printf("Enter the number of non zero elememts in the original sparse matrix = ");
	scanf("%d",&t2[0][2]);
	printf("Enter the remaining non-zero elements of the original sparse matrix:\n");
	input(t2);
	printf("\nTriplet Matrix 1 is:\n");
	display(t1);
	printf("\n\n");
	printf("\nTriplet Matrix 2 is:\n");
	display(t2);
	printf("\n\n");
	add_trip(t1,t2,sum);
	printf("\nSum of the Two Triplet Matrix is:\n");
	display(sum);
	printf("\n\n");
	return 0;
}
void input(int x[][3])
{
	int i,t;
	t=x[0][2];
	for(i=1;i<=t;i++)
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
	int i,t;
	t=x[0][2];
	for(i=0;i<=t;i++)
	printf("%d\t%d\t%d\n",x[i][0],x[i][1],x[i][2]);
	printf("\n");
}
void add_trip(int s[][3],int t[][3],int ss[][3])
{
	ss[0][0]=s[0][0];
	ss[0][1]=s[0][1];
	int i=1,j=1,k=1;
	if(s[0][0]!=t[0][0] || s[0][1]!=t[0][1])
	{
		printf("Order of the Entered sparse matrix is not same!!!\n");
		exit(0);
	}
	while(i<=s[0][2] && j<=t[0][2])
	{
		if(s[i][0]==t[j][0])
		{
			if(s[i][1]==t[j][1])
			{
				ss[k][0]=s[i][0];
				ss[k][1]=s[i][1];
				ss[k][2]=s[i][2]+t[j][2];
				k++;
				i++;
				j++;
			}
			else if(s[i][1]<t[j][1])
			{
				ss[k][0]=s[i][0];
				ss[k][1]=s[i][1];
				ss[k][2]=s[i][2];
				i++;
				k++;
			}
			else if(s[i][1]>t[j][1])
			{
				ss[k][0]=t[j][0];
				ss[k][1]=t[j][1];
				ss[k][2]=t[j][2];
				j++;
				k++;
			}
		}
		else if(s[i][0]<t[j][0])
		{
			ss[k][0]=s[i][0];
			ss[k][1]=s[i][1];
			ss[k][2]=s[i][2];
			i++;
			k++;
		}
		else if(s[i][0]>t[j][0])
		{
			ss[k][0]=t[j][0];
			ss[k][1]=t[j][1];
			ss[k][2]=t[j][2];
			j++;
			k++;
		}
	}
	//Copy The remaining elements
	while(i<=s[0][2])
	{
		ss[k][0]=s[i][0];
		ss[k][1]=s[i][1];
		ss[k][2]=s[i][2];
		i++;
		k++;
	}
	while(j<=t[0][2])
	{
		ss[k][0]=t[j][0];
		ss[k][1]=t[j][1];
		ss[k][2]=t[j][2];
		j++;
		k++;
	}
	k--;
	ss[0][2]=k;
}
