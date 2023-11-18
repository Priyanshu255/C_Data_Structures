#include <stdio.h>
int main()
{
    int arr[100];
    int i, search, size;
    printf("Enter size of the array: ");
    scanf("%d", &size);

    printf("Enter elements in the array: ");
    for(i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(i=0; i<size; i++){
        int j, c=0;
        for (j=1; j<=arr[i]; j++){
            if (arr[i]%j == 0){
                c= c+1;
            }
        }
        if (c == 2){
            printf("%d is a prime number.\n", arr[i]);
        }else{
            printf("%d is not a prime number.\n", arr[i]);
        }
    }
}