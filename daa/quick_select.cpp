#include<iostream>
using namespace std;
 
// wap to find the kth largest and kth smallest element in an array 

int partition(int * arr, int low, int high){
    int pivot = high;
    int i = low - 1;
    for(int j = low; j<high;j++){
        if(arr[j]<arr[pivot]){
            i++;
            swap(arr[j],arr[i]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1 ;
}
 
int quick_select(int * arr,int low, int high , int key){
    if(low<=high){
        int pivot = partition(arr,low,high);
        if(pivot  == key){
            return arr[pivot];
        }
        else if(pivot < key){
            return quick_select(arr,pivot+1,high,key);
        }
        else{
            return  quick_select(arr,low,pivot-1, key);
        }
        
    }
    return -1;
    
}
 
int main(){
    int arr[] = {3,6,2,5,7,1,4,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    int max = quick_select(arr,0,n-1,n-k );
    int min = quick_select(arr,0,n-1,k-1);
    cout<<"kth smallest "<<min <<endl;
    cout<<"kth largest "<< max<<endl;
    return 0;
}