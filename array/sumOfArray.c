#include <stdio.h>

int main()
{
    int num[5]={4,5,3,2,1}, i, a=0;
    for(i=0;i<5;i++){
        a = a + num[i];
    }
    printf("Sum is %d", a);
    return 0;
}

=================================================
#include <stdio.h>

int main()
{
    int num[5], i, a=0;
    
    printf("Enter numbers: ");
    
    for(i=0;i<5;i++){
        scanf("%d", &num[i]);
    }
    for(i=0;i<5;i++){
        a = a + num[i];
    }
    printf("Sum is %d", a);
    return 0;
}