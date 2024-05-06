#include<iostream>
using namespace std;
bool recursive_binarysearch(int* arr, int start, int end , int value){
    int mid = (start + end )/2;
    if(start > end) return false;
    else if (arr[mid] == value) return true;
    else if (value < arr[mid]) return recursive_binarysearch(arr, start, mid - 1, value);
    else return recursive_binarysearch(arr, mid + 1, end, value);

}
int main(){
    int t;
    cout << " enter no. of testcases : "<<endl;
    cin>> t ;
    while(t){
        int n , key;
        cout << "enter the size of array :";    
        cin>> n;
        int arr[n];
        int i = 0;
        while(i<n){
           cout<<"enter element :";
           cin>> arr[i++];
       }
        cout<<"enter the value to be searched :";
        cin>>key;
        if(recursive_binarysearch(arr,0,n,key)){
            cout << "Element is present in array "<<endl;

        }else{
            cout<<"not present in array "<<endl;
        }
        t--;
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
