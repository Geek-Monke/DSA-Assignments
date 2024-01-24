#include<stdio.h>
void swap(int *xp, int *yp){
    int temp1= *xp;
    *xp=*yp;
    *yp=temp1;
}
void selectionsort(int a[], int size){
    int i, j, temp2;
    for(i=0;i<size-1;i++){
        temp2=i;
        for(j=i+1;j<size;j++){
            if(a[j]<a[temp2]){
                temp2=j;
            }
        }
        if(temp2!=j){
            swap(&a[temp2],&a[i]);
        }
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
    selectionsort(a,n);
    printf("After sort: ");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}