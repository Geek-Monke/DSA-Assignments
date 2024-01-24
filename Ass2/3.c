#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void push(char);
char pop();
char stk[20];
int top=-1;
void push(char x)
{
    top++;
    stk[top]=x;
}
char pop()
{
    return(stk[top--]);
}
int main()
{
    int i;
    char in[20];
    printf("Enter a string :- \n");
    gets(in);
    printf("string before reverse :- \n");
    puts(in);
    printf("string after reverse :- \n");
    for(i=0;i<strlen(in);i++)
    {
	push(in[i]);
    }
   for(i=0;i<strlen(in);i++)
   {
	in[i]=pop();
   }
    puts(in);
}