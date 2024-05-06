#include<iostream>
using namespace std;
// void selection_sort(int arr[], int n ){
//     for (int i = 0; i < n-1 ; ++i) {
        
//         int min_idx = i;
//         for (int j = i +  1; j < n; ++j){
//             if (arr[j] < arr[min_idx]){
//                 min_idx = j;
//             }
//         }
//         int temp = arr[i];
//         arr[i] = arr[min_idx];  
//         arr[min_idx] = temp;
//     }
     
// }

void selection_sort(int* arr, int n){
    for(int i = 0; i<n-1;i++){
        int index = i;
        int min = i;
        for(int j = i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        swap(arr[index],arr[min]);
    }
}

void printarr(int arr[], int n ){
    int i = 0 ;
    while(i<n){
        cout << arr[i++] << " ";
    }
    cout<<endl;
}
int main(){
    int n;
    cout<<"enter number of testcases : ";
    cin>> n;

    while(n){
        cout << "enter the size of array :";
    cin>> n;
    int arr[n];
    int i = 0;
    while(i<n){
        cout<<"enter element :";
        cin>> arr[i++];
    }
    printarr(arr,n);
    // int arr[] = {4, 23, 67, 89, 10};
    selection_sort(arr,n);
    printarr(arr,n);
    n--;
    }
    
    return 0;
}