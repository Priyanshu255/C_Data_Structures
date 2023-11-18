#include <stdio.h>

int main(){
    int matrix[3][3] = {{2,3,4},{4,6,2},{4,2,1}};
    printf("Printing the matrix:\n");
    for(int i=0; i<3; i++){
		printf("row%d\t: ",i+1);
		for(int j=0; j<3; j++){
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
}