//Program to Reverse a string using Stacks
/*Designed by Aditya
  Dated 26th April 2022
  Editor- VI UNIx
*/
#define size 100
#include <stdio.h>
#include <stdlib.h>
int top;
void push(char x[],char r)
{
    if(top==size-1)
    {
        printf("Stack Overflow!!!\n");
        exit(0);
    }
    top++;
    x[top]=r;
}
char pop(char x[])
{
    char t;
    if(top==-1)
    {
        printf("Stack Underflow!!!\n");
        exit(0);
    }
    t=x[top];
    top--;
    return t;
}
//Main function
int main()
{
    char stack[size],i;
    char str[30],str_rev[30];
    top=-1;
    //Taking Input of a string
    printf("Enter a String = ");
    scanf("%s",str);
    for(i=0;str[i]!='\0';i++)
    push(stack,str[i]);
    //Reversing the string using stack
    i=0;
    while(top!=-1)
    str_rev[i++]=pop(stack);
    str_rev[i]='\0';
    printf("\nRequired Reverse String is: %s\n",str_rev);
    return 0;
}