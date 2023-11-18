#include <stdio.h>

int main(){
    int var=5;
    int *p;

    p = &var;

    printf("The value of var is: %d\n", var);
    printf("The address of var is :%p\n", p);
    printf("The value of var using pointer is: %d\n", *p);
}