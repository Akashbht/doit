#include<iostream>

using namespace std;
void heapify(int* arr, int n , int i){
    int c1 = 2 * i +1;
    int c2 = 2 * i + 2;
    int max = i;
    if(c1<n && arr[c1] > arr[max]){
        max = c1;
    }
    if(c2 < n && arr[c2] > arr[max]){
        max = c2;
    }
    if(max != i){
        swap(arr[i], arr[max]);
        heapify(arr,n,max);
    }
}
void build_heap(int* arr, int n){
    for(int i =n/2;i >= 0;  i--){
        heapify(arr, n ,i);
    }
}
void extract_max(int* arr, int n){
 
    if(n<=0) return;
    int max = arr[0];
    
    int temp = arr[0];
    arr[0] = arr[n-1];
    arr[n-1] = temp;

    n = n-1;
    heapify(arr,n,0);


}
void heap_sort(int * arr, int n){
    build_heap(arr, n);
    for(int i = 0; i<n;i++){
        extract_max(arr,n-i);
    }
     
}

int main(){
    int arr[9] = {9,8,7,6,5,4,3,2,1};
    heap_sort(arr,9);
    for(int i : arr){
        cout<<i<<" ";
    }
    return 0;
}