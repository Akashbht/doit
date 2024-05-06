#include<iostream>

using namespace std;
// int partition(int* arr, int l ,int r){
//     int pivot = arr[r];
//     int i = l-1;
//     for(int j = l; j<r;j++){
//         if(arr[j]<=pivot){
//             i++;
//             swap(arr[i],arr[j]);
//         }
//     }
//     swap(arr[i+1],arr[r]);
//     return i+1;
// }
// void quick_sort(int* arr, int l, int r){
//     if(l<r){
//         int pivot = partition(arr,l,r);
//         quick_sort(arr,l,pivot-1);
//         quick_sort(arr,pivot+1,r);
//     }
// }
int partition(int* arr, int low, int high){
    int pivot = high;
    int i = low - 1;
    for(int j = low;j<high;j++){
        if(arr[j]<arr[pivot]){
            i++;
            swap(arr[j],arr[i]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}
void quick_sort(int * arr, int low, int high){
    if(low<high){
        int pivot = partition(arr,low,high);
        quick_sort(arr,low,pivot-1);
        quick_sort(arr,pivot+1,high);
    }
}

int main(){
    int arr[9] = {9,8,7,6,5,4,3,2,1};
    quick_sort(arr,0,9);
    for(int i : arr){
        cout<<i<<" ";
    }
    return 0;
}