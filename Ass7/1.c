#include<stdio.h>

void bubblesort(int a[], int size){
    int i, j, temp;
    for(i=0;i<size-1;i++){
        for(j=0;j<size-1-i;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
int main(){
    int a[100], i, n;

    printf("Enter number of elements: \n");
    scanf("%d", &n);

    for(i=0;i<n;i++){
        printf("Enter the number: \n");
        scanf("%d", &a[i]);
    }

    bubblesort(a,n);

    printf("After sort: \n");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
