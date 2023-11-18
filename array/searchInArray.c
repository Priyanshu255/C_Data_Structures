#include <stdio.h>

int main()
{
    int arr[5], i, num;
    printf("Enter the array: \n");
    for(i=0;i<5;i++){
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the number: ");
    scanf("%d", &num);
    for (i=0;i<5;i++){
        if (arr[i]==num){
            printf("Number found at place %d", i+1);
            break;
        }
        else{
            continue;
        }
    }
    return 0;
}