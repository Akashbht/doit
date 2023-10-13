#include <stdio.h>
#include <stdlib.h>

void input(int** arr,int row,int col){
    for(int i= 0; i< row;i++){
        for(int j = 0; j< col; j++){
            printf("enter element arr[%d][%d]: ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
}
void printarr(int** arr,int row,int col){
    for(int i= 0; i< row;i++){
        for(int j = 0; j< col; j++){
            printf("\t%d",arr[i][j]);
        }
        printf("\n");
    }
}
int main(void) {
    int row, col;
    printf("Enter the number of rows: ");
    scanf("%d", &row);
    printf("Enter the number of columns: ");
    scanf("%d", &col);
    
    int** arr = (int**)malloc(sizeof(int*)*row);
    for(int i = 0; i< row;i++){
        arr[i] = (int*)malloc(sizeof(int*)*col);

    }
    input(arr,row,col);
    printarr(arr,row,col);
	return 0;
}