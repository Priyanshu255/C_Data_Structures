#include <stdio.h>

int main()
{
    int data[] = {9, 5, 1, 4, 3};
    int size = sizeof(data) / sizeof(data[0]);
    
    printf("\nBefore: ");
    for (int i=0; i<size; i++){
        printf("%d ", data[i]);
    }
    
    for(int step = 1; step<size; step++){
        int key = data[step];
        int j = step-1;
        while(key<data[j] && j>=0){
            data[j+1] = data[j];
            --j;
        }
        data[j+1] = key;
    }
    
    printf("\nAfter: ");
    for (int i=0; i<size; i++){
        printf("%d ", data[i]);
    }
    return 0;
}
