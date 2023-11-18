#include <stdio.h>

int main()
{
    int arr[5], arr2[5], i, a, j, num;
    printf("Enter the array: \n");
    for(i=0;i<5;i++){
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    }
    
    printf("Array in ascending order: ");
    for (i=0;i<5;i++){
        for (j=i+1;j<5;j++){
            if (arr[i]>arr[j]){
                a = arr[j];
                arr[j] = arr[i];
                arr[i] = a;
            }
        }
    }
    for(i=0;i<5;i++){
        printf("%d", arr[i]);
    }
    return 0;
}