#include <stdio.h>

int arr[3][3];
int ans[3][3];


void getmatrix(){
	for(int i=0; i<3; i++){
		printf("Enter row %d: ",i+1);
		for(int j=0; j<3; j++){
			scanf("%d", &arr[i][j]);
		}
	}
}

void printmatrix(int arr[3][3]){
	for(int i=0; i<3; i++){
		printf("row%d\t: ",i+1);
		for(int j=0; j<3; j++){
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
}

void transposeMatrix(){
	for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            ans[j][i] = arr[i][j];
        }
    }
}

int main(){
    printf("Enter the matrix: \n");
    getmatrix(arr);
    printf("Entered matrix is: \n");
    printmatrix(arr);
    printf("Transpose of the given matrix is: \n");
    transposeMatrix();
    printmatrix(ans);
}