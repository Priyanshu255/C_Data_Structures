#include <stdio.h>
void printarry(int array[], int size){
    for(int i=0; i<size; i++){
        printf("%d ", array[i]);
    }
}


void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    //printf("\npivot: %d",pivot);
    int i = (low-1);

    for (int j = low; j<high; j++){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
            //printf("\ninside if %d:\n", j);
            //printarry(arr,high);
        }
        //printf("\noutside if %d:\n", j);
        //printarry(arr,high);
    }
    swap(&arr[i+1], &arr[high]);
    //printf("\n ==================pass finish:\n");
    //printf("array output: \n");
    //printarry(arr,high);
    //printf("\nindex return: %d", i+1);
    return(i+1);
}

void quick_sort(int arr[], int low, int high){
    if (low<=high){
        int q = partition(arr, low, high);
        quick_sort(arr, low, q-1);
        quick_sort(arr, q+1, high);
    }
}


int main(){
    int arr[] = {13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11};
    int size = sizeof(arr)/sizeof(arr[0]);

    printarry(arr, size);

    quick_sort(arr,0,size-1);

    printf("\nanswer array\n");
    printarry(arr, size);

}