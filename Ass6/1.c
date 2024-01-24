#include <stdio.h>

int linearsearch(int arr[], int size, int data)
{
    int i = 0, temp = 0;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == data)
        {
            printf("Data Found.");
            temp = 1;
            break;
        }
    }
    if (temp == 0)
        printf("Data not found.");
}
int main()
{

    int arr[] = {2, 4, 6, 8, 9, 34, 45, 10, 11, 67};
    int data = 7;

    int n = sizeof(arr) / sizeof(arr[0]);

    int result = linearsearch(arr, n, data);
    return 0;
}