
// given am already sorted array of positive integers , define and algorithm and implement it using a program to find whether a given key element is present in the sorted array or not for an array A[n] search at indeces A[0] A[2] A[4] ...A[2^k], and so on. Once the interval is A[2^k] < key  < A[2^k+1] . if found , perform a linear search operation from index 2^k to find the element E , complexity should be less than o(n), where n is the number of element 



// file Ques 1

// given an array of non negative integers design a linear algorithm and implement it using a program to find whether given e element is present in an array or not ,also find total number of comparisons each input gives, O(n), and n is the input size


#include<iostream>
using namespace std;

bool linearsearch(int * arr,int size, int value){
    int i ;
    for (i = 0; i < size; i *= 2) {
        if(arr[i]==value) break;
// /        if(arr[i]<value && arr[i])

    }
    int comp = 0;

    for(int i = 0 ; i< size; i++){
        if(arr[i]==value){
            // flag = 1;
            return 1;
        }
    }
    return 0;

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
        if(linearsearch(arr,10,n)){
            cout << "Element is present in array "<<endl;

        }else{
            cout<<"not present in array "<<endl;
        }
        t--;
    }    
    

}


