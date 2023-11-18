#include <stdio.h>

int facto(int n){
    if (n==1){
        return 1;
    }
    else{
        return n*facto(n-1);
    }
}

int main(){
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);

    printf("Factorial of the given number is: %d", facto(num));
}
