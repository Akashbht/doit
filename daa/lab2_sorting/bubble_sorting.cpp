#include<iostream>
using namespace std;
void bubble_sort(int arr[], int n ){
    
    for(int i =  0; i< n-1;i++){

        for(int j = 0 ; j < n-1-i;j++){

            
            if(arr[j+1]<arr[j]){
                swap(arr[j],arr[j+1]);
            }
        }
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
    bubble_sort(arr,n);
    printarr(arr,n);
    return 0;
}