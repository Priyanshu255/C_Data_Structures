//without fuctions

#include <stdio.h>

int main()
{
    int data[] = {-2, 45, 0, 11, -9};
    
    int size = sizeof(data) / sizeof(data[0]);
    
    printf("Before: ");
    for (int i=0; i<size; i++){
        printf("%d ", data[i]);
    }
    
    //bubble sort
    for(int pass=0; pass<size; pass++){
        for (int i=0; i<size; i++){
            for (int j=0; j<size-i; j++){
                if(data[i]>data[i+1]){
                    int temp = data[i];
                    data[i] = data[i+1];
                    data[i+1] = temp;
                }
            }
        }
    }
    
    //printing the array
    printf("After: ");
    for (int i=0; i<size; i++){
        printf("%d ", data[i]);
    }
}

//with functions
/*
#include <stdio.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int arr[], int n){
    int i,j;
    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if (arr[j]>arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void printarray(int arr[], int size){
    for (int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {54, 3, 9, 23, 5, 2, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    printarray(arr, n);
    bubbleSort(arr, n);
    printf("Sorted: ");
    printarray(arr, n);
    return 0;
}
*/
