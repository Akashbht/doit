// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>

// array in  2 d ,

void input(int* arr, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Enter element at arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i* col + j]); 
        }
    }
}
void printarray(int* arr,int row,int  col){
    for (int i = 0;i<row; i++){
        for (int j  = 0 ; j<col ; j++){
            printf("%d ", arr[i * col + j]);
        }
        printf("\n");
    }
}

int maxrowsum(int arr[], int row , int col ){
    int rowsum = 0, maxsum = 0 ;
    
    for(int i = 0; i< row; i++){
        for (int j =0 ; j< col ; j++){
            rowsum += arr[i*col+j];
            
        }
        if(rowsum > maxsum) maxsum = rowsum;
        rowsum = 0;
    }
    return maxsum;
}
int maxcolsum(int arr[], int row , int col ){
    int colsum = 0, maxsum = 0;
    
    for(int i = 0; i<row;i++){
        for (int j = 0; j<col ; j++){
            colsum += arr[j*col + i];
            
        }
        if(colsum > maxsum) maxsum = colsum;
        colsum = 0;
    }
    return maxsum;
}
int main() {
    int row,col;
    printf("enter no, of rows :");
    scanf("%d",&row);
    printf("enter no, of cols :");
    scanf("%d",&col);
    int* arr = (int*)malloc(sizeof(int) * row * col);
    input(arr,row,col);
   
    
    printarray(arr,row,col);
    
    printf("max row sum is %d \n",maxrowsum(arr,row,col));
    printf("max col sum is %d \n",maxcolsum(arr,row,col));
    return 0;
}