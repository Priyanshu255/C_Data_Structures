#include <stdio.h>

int arr[10] = {4,6,8,64,9,34,23,45,12,32};
int _index;

int ispresent(int value){
    for(int i=0; i<10; i++){
        if(arr[i]==value){
            _index = i;
            return 1;
        }
    }
    return 0;
}

int main(){
    
    int value;
    printf("enter the value: ");
    scanf("%d", &value);

    int ans = ispresent(value);
    if(ans==1){
        printf("%d is present at index %d in the array.", value, _index);
    }
    else{
        printf("%d is not present in the array.", value);
    }
    
}