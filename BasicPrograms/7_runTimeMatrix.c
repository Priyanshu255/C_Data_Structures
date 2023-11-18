#include <stdio.h>

int main(){
    int matrix[3][3];

    printf("Enter the Matrix:\n");
    for(int i=0; i<3; i++){
		printf("Enter row %d: ",i+1);
		for(int j=0; j<3; j++){
			scanf("%d", &matrix[i][j]);
		}
	}

    printf("Printing the matrix:\n");
    for(int i=0; i<3; i++){
		printf("row%d\t: ",i+1);
		for(int j=0; j<3; j++){
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
}