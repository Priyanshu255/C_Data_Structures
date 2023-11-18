int main() {
    int num1[2][2], num2[2][2], product[2][2], i, j, k;
    
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
            printf("  %d  ",num1[i][j]);
        }
        printf("\n");
    }
    printf("Matrix 2: \n");
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            printf("  %d  ",num2[i][j]);
        }
        printf("\n");
    }
    // compulsary always
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            product[i][j]=0;
        }
    }
    printf("Product of matrix:");
    for(i=0;i<2;i++){
        printf("\n");
        for(j=0;j<2;j++){
            for(k=0;k<2;k++){
                //product[i][j] = num1[i][k]*num2[k][j] + num1[i][k]*num2[k][j];
                product[i][j] += num1[i][k]*num2[k][j];
            }
            printf("  %d  ",product[i][j]);
        }
    }
    
    return 0;
}
