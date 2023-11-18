/*
// entering and displaying the 2d array

#include <stdio.h>

int main() {
    int num[3][3], i, j, a, b;

    for(i=0;i<3;i++){
        printf("Enter row %d: ",i+1);
        for(j=0;j<3;j++){
            scanf("%d", &num[i][j]);
        }
    }

    for(i=0;i<3;i++){
        printf("Row %d: ",i+1); 
        for(j=0;j<3;j++){
            printf("%d ",num[i][j]);
        }
        printf("\n");
    }
    return 0;
}
*/

// entering no. of rows and columns and then array and then printing them

#include <stdio.h>
int main() {
    int r, c, i, j;
    printf("Enter number of rows: ");
    scanf("%d",&r);
    printf("Enter number of columns: ");
    scanf("%d",&c);
    int num[c][r];
    for(i=0;i<r;i++){
        printf("Enter row %d: ",i+1);
        for(j=0;j<c;j++){
            scanf("%d", &num[i][j]);
        }
    }
    printf("\n");
    
    for(i=0;i<r;i++){
        printf("Row %d: ",i+1);
        for(j=0;j<c;j++){
            printf("%d ", num[i][j]);
        }
        printf("\n");
    }

}