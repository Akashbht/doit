// # given an unsorted array of integer , design an algo and implement it using a program to find wiether two element exist such that their sum is equal to the given key element 
// # time complexity - O(nlogn)

#include<vector>
#include<bits/stdc++.h>
using namespace std;

bool binarysearch(int* arr, int start, int end , int value){
    if(start<=end){
        int mid = start +(end-start)/2;
        if(arr[mid]==value) return true;
        else if(arr[mid]>value) return binarysearch(arr,start, mid-1, value);
        else return  binarysearch(arr,mid+1,end,value);

    }else{
        return false;
    }

}
void twoSum(int* arr, int n, int target){
    for(int i = 0 ;i<n-1;i++){
        if(binarysearch(arr,i+1,n-1,target-arr[i])== true){
            cout<<"element pair found "<<endl;
            cout<<"first element :"<<arr[i]<<endl;
            cout<<"second element:"<<target-arr[i]<<endl;
            return;
        }
    }
    cout<<"not found "<<endl;
    
}

int main(){
    int arr[] = {90,34,364,376,43,3562,48};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr, arr+n); 
    twoSum(arr, n,77);

    return 0;
}
