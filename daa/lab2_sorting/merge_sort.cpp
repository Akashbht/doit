#include<iostream>
using namespace std;

// void merge(int * arr, int low, int mid , int high){
//     int n1, n2;
//     n1 = mid-low + 1;
//     n2 = high - mid;
//     int LEFT[n1],RIGHT[n2];
//     // int k = 0;
//     for(int i = 0 ;i < n1;i++){
//         LEFT[i] = arr[low+i];
//     }
//     for(int j = 0 ;j < n2 ;j++) {
//         RIGHT[j] = arr[mid + 1 + j];
//     }
//     int i = 0,j =0,k =0;
//     while(i < n1 && j< n2){
//         if(LEFT[i]<RIGHT[j]){
//             arr[k++] = LEFT[i++];
//         }else{
//             arr[k++] = RIGHT[j++];
//         }
//     }
//     while(i < n1){
//         arr[k++]=LEFT[i++];
//     }
//     while(j<n2){
//         arr[k++] = RIGHT[j++];
//     }
// }
// void merge_sort(int* arr,int low, int high){
//     if (low < high) {
//         int mid = (low + high )/2;
//         merge_sort(arr,low,mid);
//         merge_sort(arr,mid+1,high);
//         merge(arr,low,mid,high);
//     }
// }


 
void printarr(int arr[], int n ){
    int i = 0 ;
    while(i<n){
        cout << arr[i] << " ";
        i++;
    }
    cout<<endl;
}



void merge(int * arr, int low , int mid, int high){
    int n1 = mid -low+1; 
    int n2 = high- mid;
    int L[n1], R[n2];
    for(int i = 0; i< n1;i++){
        L[i] = arr[low+i];
    }
    for(int i = 0; i<n2;i++){
        R[i]= arr[mid+i+1];
    }

    int i = 0, j = 0 , k = low;
    while(i<n1 && j < n2){
        if(L[i] < R[j]){
            arr[k++] = L[i++];
        }
        else{
            arr[k++] = R[j++];
        }
    }
    while(i<n1){
        arr[k++] = L[i++];
    }
    while(j<n2){
        arr[k++] = R[j++];
    }
}
void merge_sort(int* arr, int low, int high){
    if(low<high){
        int mid = low + (high-low) /2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}



int main(){
    int n ;
    cout<<"enter the size of array";
    cin >> n;
    int arr[n];
    int i = 0;
    cout<<"enter the values for array :";
    while(i<n){
        cin>> arr[i];
        i++;
    }     
    printarr(arr,n);
    merge_sort(arr,0,n-1);
    printarr(arr,n);
    return 0;
}

