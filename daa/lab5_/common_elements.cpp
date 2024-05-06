#include<bits/stdc++.h>
using namespace std;
void common_elements(int* arr1, int* arr2, int n, int m){
    int max = 0;
    for(int i=0; i< n; i++){
        if (arr1[i] > max) {
            max = arr1[i];
        }
    }
    for(int i=0; i< m; i++){
        if (arr2[i] > max) {
            max = arr1[i];
        }
    }
    vector <int> hash(max+1);
    for(int i=0; i<n; i++)
        hash[arr1[i]]++;
    
    cout << "Common elements are : ";
    for(int i=0; i<m; i++){
        hash[arr2[i]]++;
        if(hash[arr2[i]]>1){
            cout << arr2[i] << " ";
        }
    }
    cout<<endl;
}

int main(){
    int t;
    cout<<"enter the number of testcases";
    cin>>t;
    while(t--){
        int n1,n2;
        cout<<"size of array 1 :";
        cin>>n1;
        int arr1[n1];
        cout<<"enter element for array 1:"<<endl;
        int i = 0;
        while(i<n1){
            cin >> arr1[i++];
        }
        cout<<"Size of array 2:";
        cin>>n2;
        int arr2[n2];
        cout<<"enter element for array 1:"<<endl;
        i = 0;
        while(i<n2){
            cin >> arr2[i++];
        }
        common_elements(arr1,arr2,n1,n2);
    }    
 
    return 0;
}