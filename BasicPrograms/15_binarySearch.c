#include <stdio.h>

int main(){
    int arr[10] = {0,1,2,4,6,7,8,12,18,20};
    int start = 0;
    int end = 9;
    int mid = (start + end)/2;

    int key;
    printf("Enter the value to be searched: ");
    scanf("%d", &key);
    while(start<=end){
        if (arr[mid] == key){
            printf("The value %d found at index %d.", key, mid);
        }

        if (key > arr[mid]){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
        mid = start + (end - start)/2;
    }
    return 0;
}