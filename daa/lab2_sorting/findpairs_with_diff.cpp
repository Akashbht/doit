#include<iostream>
using namespace std;

//  given a sorted array of positive integers design an algorithm to count the no if pairs of integers such that their difference is equal to the given key




int findpairs(int arr[] , int n, int diff){
    int count = 0;
    for(int i = 0; i < n;i++){
        for(int j = i+1; j<n;j++){ 
            if((arr[i]-arr[j]==diff )||( arr[j]-arr[i]==diff)){
                count++;
                cout <<"pair found : "<< arr[i]<<","<<arr[j]<<endl;
            }
        }
    }

    cout<<"no of pairs with diff is : "<<count<<endl;

    
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
    cout<<"enter the difference to be checked:";
    cin >>x;
    findpairs(arr,n,x);
    
    return 0;
}