#include <stdio.h>

// Functions to input and print a 2D array

void input(int arr[][10], int row, int col){
    for(int i = 0; i< row; i++){
        for(int j = 0  ; j< col ; j++){
            printf("enter element arr[%d][%d] :",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
}

void printarray(int arr[][10], int row, int col){
    for(int i = 0; i<row;i++){
        for(int j=0;j<col;j++){
            printf("\t %d ",arr[i][j]);
        
        }
        printf("\n");
    }
}

int main() {
    int row, col;
    printf("Enter the number of rows: ");
    scanf("%d", &row);
    printf("Enter the number of columns: ");
    scanf("%d", &col);
    
    int arr[10][10]; // Define a 2D array (adjust the size as needed)
    
    if (row > 10 || col > 10) {
        printf("Array size too large.\n");
        return 1;
    }
    
    input(arr, row, col);
    printarray(arr, row, col);

    return 0;
}
