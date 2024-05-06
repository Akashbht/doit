#include<iostream>
using namespace std;

bool recursive_binarysearch(int* arr, int start, int end , int value){
    if(start<=end){
        int mid = start +(end-start)/2;
        if(arr[mid]==value) return true;
        else if(arr[mid]>value) return recursive_binarysearch(arr,start, mid-1, value);
        else return recursive_binarysearch(arr,mid+1,end,value);

    }else{
        return false;
    }

}

bool iterative_binarysearch(int* arr, int size, int value ){
    int start = 0;
    int end = size - 1;
    
    while (start <= end) {
        int mid = (start+end) / 2;
        
        if (arr[mid] == value){
            return true;
        } else if(arr[mid] <value) {
            start = mid+1;
        } else {
            end = mid - 1;
        }
    }
   return false;
}


int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int t;
    cout << " enter no. of testcases : "<<endl;
    cin>> t ;
    while(t){
        int n , key;
        cout<<"enter the value to be searched :";
        cin>>n;
        if(recursive_binarysearch(arr,0,10,n)){
            cout << "Element is present in array "<<endl;

        }else{
            cout<<"not present in array "<<endl;
        }
        t--;
    }    
    

}



