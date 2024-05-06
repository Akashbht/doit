
// # given an unsorted array of integer , design an algo and implement it using a program to find wiether two element exist such that their sum is equal to the given key element 
// # time complexity - O(nlogn)

//   given an unsorted array of alphabets containing duplilcate elements, design an algo and implement if using the program to find which alphabet as maximum no. of occurance and print it 
//  time complexity - O(n)


#include<vector>
#include<bits/stdc++.h>
using namespace std;

int findMaxOccurances(int* arr, int n){
    
    int max = 0;
    for(int i=0;i<n;i++){
        if(arr[i]>max) max = arr[i];
    }
    vector<int> hash(max,0);
    for(int i = 0; i<n;i++){
        hash[arr[i]]++;
    }
    max = 0;
    for(auto &x : hash){
       if(x > max) max = x;  
    }
    return max;
}

int main(){
    int arr[] = {10,10,10,20, 20, 30,40,40,40, 40, 50, 60};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "The maximum number of occurrences is : "<<findMaxOccurances(arr, n);

    return 0;
}
