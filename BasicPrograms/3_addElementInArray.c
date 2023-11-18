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

    printf("enter the index: ");
    scanf("%d", &index);
    printf("enter the element to be added: ");
    scanf("%d", &value);
        
    for(int i=5; i>=index; i--){
        arr[i+1]=arr[i];
    }

    arr[index] = value;

    printf("Array is: ");

    for(int j=0; j<6; j++){
        printf("%d ", arr[j]);
    }

}