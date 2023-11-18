#include <stdio.h>

void getmatrix(int arr[20][20],int row, int col){
	for(int i=0; i<row; i++){
		printf("Enter row %d: ",i+1);
		for(int j=0; j<col; j++){
			scanf("%d", &arr[i][j]);
		}
	}
}

void printmatrix(int arr[20][20],int row, int col){
	for(int i=0; i<row; i++){
		printf("row %d\t: ",i+1);
		for(int j=0; j<col; j++){
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
}

void multiplymatrix(int arr1[20][20], int arr2[20][20], int ans[20][20], int row1, int col1, int row2, int col2){
	for(int i=0; i<row1; i++){
		for(int j=0; j<col2; j++){
			int sum = 0;
			for(int k=0; k<col1; k++){
				sum = sum + arr1[i][k]*arr2[k][j];
			}
			ans[i][j]=sum;
		}
	}
}

int main()
{
    int arr1[20][20];
    int arr2[20][20];
    int ans[20][20];
    printf("enter matrix 1: \n");
    getmatrix(arr1,3,3);
    printf("enter matrix 2: \n");
    getmatrix(arr2,3,3);
    
    printf("matrix 1: \n");
    printmatrix(arr1,3,3);
    printf("matrix 2: \n");
    printmatrix(arr2,3,3);
    
    multiplymatrix(arr1,arr2,ans,3,3,3,3);
    
    printf("answer matrix: \n");
    printmatrix(ans,3,3);

    return 0;
}