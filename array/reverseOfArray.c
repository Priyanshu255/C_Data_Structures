#include <stdio.h>

void main()
{
    int num[5];
    int i;
    printf("Enter numbers: \n");
    for (i=0;i<5;i++){
        printf("Number %d: ",i+1);
        scanf("%d",&num[i+1]);
    }
    printf ("Reverse: ");
    for (i=5;i>0;i--){
        printf("%d ",num[i]);
    }
}

