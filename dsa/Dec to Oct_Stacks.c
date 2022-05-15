//Program to convert Decimal number to Octal using stacks
/*Designed by Aditya
  Dated 26th April 2022
  Editor- VI UNIx
*/
#define size 100
#include <stdio.h>
#include <stdlib.h>
int top;
void push(int x[],int r)
{
    if(top==size-1)
    {
        printf("Stack Overflow!!!\n");
        exit(0);
    }
    top++;
    x[top]=r;
}
void display(int x[])
{
    int i;
    if(top==-1)
    {
        printf("The Stack is Empty!!!\n");
        exit(0);
    }
    for(i=top;i>=0;i--)
    printf("%d ",x[i]);
    printf("\n");
}
int main()
{
    int stack[size],deci,original;
    top=-1;
    printf("Enter a Decimal number = ");
    scanf("%d",&deci);
    original=deci;
    while(deci>0)
    {
        push(stack,deci%8);
        deci/=8;
    }
    printf("\nOctal form of %d:\n",original);
    display(stack);
    return 0;
}