#include <stdio.h>

int main()
{
    int arr[5];
    printf("\n\n");
    
    for(int i=0; i<5; i++){
        printf("enter %d element: ",i+1);
        scanf("%d", &arr[i]);
    }
    
    printf("Array is: ");
    
    for(int i=0; i<5; i++){
        printf("%d ", arr[i]);
    }
    printf("\n\n");

}