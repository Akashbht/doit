
// given an array of non negative integers , design an algorithm and a program to count the number of pairs of integer such that the difference is equal to the given e (element)

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


void find_diff(int* arr, int size, int target){
    int max = 0;
    for(int i = 0;i<size;i++){
        if(max<arr[i]) max = arr[i];
    }
    vector<int> hash(max + 1 , 0);
    for(int i=0;i<size;i++) hash[arr[i]]++;
    for(int i=0;i<=max;i++){
        if(hash[target+arr[i]]>0){
            cout<<"pair found :";
            cout<<arr[i]<<" "<<target+arr[i];
            cout <<endl;
            return;
        }
    
    }

}
int main(){
    int t;
    cout<<"no. of testcases :";
    cin>> t;
    while(t){
        int n ;
        cin>>n;
        int arr[n];
        for(int i = 0; i< n;i++){
            cin>>arr[i];
        }
        cout<<"enter the target :";
        int target;
        cin>> target;
        find_diff(arr , n ,target);
        t--;
    }
}




