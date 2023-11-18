
#include <stdio.h>

void main()
{
    char name[10];
    int i;
    printf("Enter characters of name: \n");
    for (i=0;i<17;i++){
        printf("character %d: ",i+1);
        scanf("%c",&name[i+1]);
    }
    printf ("Name is: ");
    for (i=0;i<17;i++){
        printf("%c",name[i+1]);
    }
}
