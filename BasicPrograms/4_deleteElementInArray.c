#include <stdio.h>

int main()
{
    int index;
    int value;
    int arr[10];
    
    for(int i=0; i<5; i++){
        printf("enter %d element: ",i+1);
        scanf("%d", &arr[i]);
    }

    printf("enter the index whose value is to be deleted: ");
    scanf("%d", &index);
        
    for(int i=index; i<=5; i++){
        arr[i]=arr[i+1];
    }

    printf("Array is: ");

    for(int j=0; j<4; j++){
        printf("%d ", arr[j]);
    }

}