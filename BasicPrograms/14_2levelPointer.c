#include <stdio.h>

int main(){
    int var=4;
    int *p1;
    int **p2;

    p1 = &var;
    p2 = &p1;

    printf("The value of var is: %d\n", var);
    printf("The address of var is :%p\n", p1);
    printf("The value of var using single pointer is: %d\n", *p1);
    printf("The address of p1 is :%p\n", p2);
    printf("The address of var using double pointer is: %p\n", *p2);
    printf("The value of var using double pointer is: %d\n", **p2);


}