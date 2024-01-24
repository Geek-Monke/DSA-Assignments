#include <stdio.h>

void insertionsort(int a[], int size)
{
    int i, j, temp;
    for (i = 0; i < size; i++)
    {
        temp = a[i];
        j = i - 1;
        while (j >= 0 && temp < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j+1]=temp;
    }
}
int main()
{
    int a[100], i, n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the number: ");
        scanf("%d",&a[i]);
    }
    insertionsort(a,n);
    printf("After sort: ");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}