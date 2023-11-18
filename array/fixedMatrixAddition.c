#include <stdio.h>

int main() {
    int num1[2][2], num2[2][2], i, j, sum[2][2];
    
    printf("Enter matrix 1: \n");
    for(i=0;i<2;i++){
        printf("Enter row %d: ",i+1);
        for(j=0;j<2;j++){
            scanf("%d", &num1[i][j]);
        }
    }
    printf("Enter matrix 2: \n");
    for(i=0;i<2;i++){
            printf("Enter row %d: ",i+1);
            for(j=0;j<2;j++){
                scanf("%d", &num2[i][j]);
            }
    }
    printf("Matrix 1: \n");
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            printf(" %d ",num1[i][j]);
        }
        printf("\n");
    }
    printf("Matrix 2: \n");
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            printf(" %d ",num2[i][j]);
        }
        printf("\n");
    }
    printf("Sum matrix:");
    for(i=0;i<2;i++){
        printf("\n");
        for(j=0;j<2;j++){
            sum[i][j]= num1[i][j] + num2[i][j];
            printf(" %d ",sum[i][j]);
        }
    }
    
    return 0;
}
