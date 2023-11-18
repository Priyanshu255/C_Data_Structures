#include <stdio.h>

int arr1[3][3];
int arr2[3][3];
int ans[3][3];

void getmatrix(int arr[3][3]){
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

void addMatrix(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            ans[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
}

int main()
{
    printf("enter matrix 1: \n");
    getmatrix(arr1);
    printf("enter matrix 2: \n");
    getmatrix(arr2);
    
    printf("matrix 1: \n");
    printmatrix(arr1);
    printf("matrix 2: \n");
    printmatrix(arr2);
    
    addMatrix();
    
    printf("answer matrix: \n");
    printmatrix(ans);

    return 0;
}