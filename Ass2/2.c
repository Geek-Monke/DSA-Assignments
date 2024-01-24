#include <stdio.h>
#include <stdlib.h>
int top = -1;

struct student
{
    int roll;
    char name[30];
    int math_marks, eng_marks;
} s[10];
void push()
{
    if (top == 9)
    {
        printf("\n Stack overflow");
        return;
    }
    else
        top++;
    printf("Enter details for student %d:\n", top+1);
    printf("Roll No: ");
    scanf("%d", &s[top].roll);
    printf("Name: ");
    scanf(" %s", &s[top].name);
    printf("Math marks: ");
    scanf("%d", &s[top].math_marks);
    printf("English marks: ");
    scanf("%d", &s[top].eng_marks);
}
void pop()
{
    if (top == -1)
    {
        printf("\n Stack underflow");
        return;
    }
    else
    {
        printf("deleted data:\n");
        printf("Roll No:%d\n", s[top].roll);
        printf("Name:%s\n", s[top].name);
        printf("Math Marks:%d\n", s[top].math_marks);
        printf("English marks:%d\n", s[top].eng_marks);
        top--;
    }
}
void display()
{
    int i;
    if (top == -1)
    {
        printf("\n Stack underflow");
        return;
    }
    printf("\n Student info:\n");
    for (i = top; i >= 0; i--)
    {
        printf("\n Roll No:%d\n", s[i].roll);
        printf("Name:%s\n", s[i].name);
        printf("Math Marks:%d\n", s[i].math_marks);
        printf("English marks:%d\n", s[i].eng_marks);
        printf("Total marks:%d \n", s[i].math_marks + s[i].eng_marks);
    }
}
int main()
{
    int ch;
    while (1)
    {
        printf("1 for Input data \n");
        printf("2 for Delete data \n");
        printf("3 for Display data\n");
        printf("4 for Quit \n");
        printf("Enter Choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("enter valid choice");
        }
    }
}