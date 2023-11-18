#include <stdio.h>

void main()
{
    int marksphy[10], markschem[10],i;
    for(i=1;i<=10;i++){
        printf("Enter marks of student %d \n",i);
        printf("For physics: ");
        scanf("%d", &marksphy[i]);
        printf("For chemistry");
        scanf("%d", &markschem[i]);
    }
    
    for(i=1;i<=10;i++){
        printf("Marks of student %d ",i);
        printf("Chemistry marks-\n");
        printf("Chemistry marks: %d \n",marksphy[i]);
        printf("Chemistry marks: %d \n",marksphy[i]);
    }
    
}
