#include <stdio.h>

int main()
{
    int data[] = {20, 12, 2, 15, 10};
    
    int size = sizeof(data) / sizeof(data[0]);
    
    printf("Before: ");
    for (int i=0; i<size; i++){
        printf("%d ", data[i]);
    }
    
    //Selection sort
    for (int step=0; step<size-1; step++){
        int min_id=step;
        //printf("let: %d ",data[min_id]);
        //printf("\npass %d\n", step);
        for (int i=step+1; i<size; i++){
            //printf("\nj: %d\n", i);
            if(data[i]<data[min_id]){
                min_id = i;
                //printf("let inside: %d ",data[min_id]);
            }
            int temp = data[min_id];
            data[min_id] = data[step];
            data[step] = temp;
            //printf("\nAfter: ");
            //    for (int i=0; i<size; i++){
            //       printf("%d ", data[i]);
            //    }
            
        }
    }
    
    //printing the array
    printf("\nAfter: ");
    for (int i=0; i<size; i++){
        printf("%d ", data[i]);
    }
}

