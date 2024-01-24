#include <stdio.h>

int linearsearch(int arr[], int size, int data)
{
    int i = 0, temp = 0;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == data)
        {
            printf("Data Found at location %d.",i+1);
            temp = 1;
            break;
        }
    }
    if (temp == 0)
        printf("Data not found.");
}
int main()
{
    int arr[10], data;
    printf("Enter the 10 elements.\n");
    for(int i=0;i<10;i++){
        printf("Enter the number: ");
        scanf("%d",&arr[i]);
    }
    printf("Enter the Data to search: \n");
    scanf("%d",&data);

    int n = sizeof(arr) / sizeof(arr[0]);

    int result = linearsearch(arr, n, data);
    return 0;
}