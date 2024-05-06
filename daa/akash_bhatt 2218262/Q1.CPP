#include<iostream>
using namespace std;
bool linearsearch(int * arr,int size, int value){
    for(int i = 0 ; i< size; i++){
        if(arr[i]==value){
            return 1;
        }
    }
    return 0;
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
        cin>>n;
        if(linearsearch(arr,10,n)){
            cout << "Element is present in array "<<endl;
        }else{
            cout<<"not present in array "<<endl;
        }
        t--;
    }    
}
