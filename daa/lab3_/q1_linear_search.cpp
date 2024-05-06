// file Ques 1

// given an array of non negative integers design a linear algorithm and implement it using a program to find whether given e element is present in an array or not ,also find total number of comparisons each input gives, O(n), and n is the input size


#include<iostream>
using namespace std;

bool linearsearch(int * arr,int size, int value){
    // if(size == -1){
    //     return false;
    // }
    // if(arr[size-1]==value){
    //     return true;
    // }
    // else{
    //     return linearsearch(arr,size-1,value);
    // }

    // int flag = 0;
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



