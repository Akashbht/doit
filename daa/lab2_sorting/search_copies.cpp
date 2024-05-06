#include<iostream>
using namespace std;

//  given a sorted array of positive integers containing few duplicate elements , design and algo and implement it using a program to find whether a given e element is present in an array or not. if present  then also find the number of copies of given e , with time complexity O(logn);

int binarysearch(int* arr, int start, int end , int value){
    int mid = (start + end )/2;
    if(start > end) return 0; 
    
    else if (arr[mid] == value) return mid;
    else if (value < arr[mid]) return binarysearch(arr, start, mid - 1, value);
    else return binarysearch(arr, mid + 1, end, value);

}
int findcopies(int arr[], int n, int x ){
    int res = binarysearch(arr,0,n-1,x);
    if(res){
        cout  << "Element is present at index :"<< res<<endl ;
    }else{
        cout << "\n Element is not present in array"<<endl;
        return 0;
    }
    int i = 0;
    int high_in = res;
    int low_in = res;

    while(arr[high_in]==x){
        i++;
        high_in++;
    }
    while(arr[low_in-1]==x){
        i++;
        low_in--;
    }
    cout<<"there are "<<i<<" copies of element in the arr"<<endl;
    return i;
        
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
    int x;
    cout<<"enter the element to be checked for :";
    cin >>x;
    findcopies(arr,n,x);
    
    return 0;
}