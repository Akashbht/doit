// file Ques 2


#include<iostream>
using namespace std;



// given a sorted array of sorted integers design an algo and implement it to find the index i,j,k such that               A[i]+A[j] =   A[k] 



int iterative_binarysearch(int* arr, int size, int value ){
    int start = 0;
    int end = size - 1;
    
    while (start <= end) {
        int mid = (start+end) / 2;
        
        if (arr[mid] == value){
            return mid;
        } else if(arr[mid] <value) {
            start = mid+1;
        } else {
            end = mid - 1;
        }
    }
   return -1;
}


void checkpairs(int arr[],int size ){
    for(int i = 0 ; i<size-1 ;i++ ){
        for(int j = i+1 ; j<size ;j++){
            if(iterative_binarysearch(arr,10,arr[i]+arr[j])!= -1 ){
                cout << "Pair found :"<< arr[i] << "," << arr[j]<< "=" << arr[iterative_binarysearch(arr,10,arr[i]+arr[j])];
                cout<<endl;
                // return;
            }
            

        }
        // cout << endl;
    }
}
int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int t;
    // cout << " enter no. of testcases : "<<endl;
    cout<<"no. of testcases :";
    cin>> t;
    while(t){
        int n ;
        cin>>n;
        int arr[n];
        for(int i = 0; i< n;i++){
            cin>>arr[i];
        }
        checkpairs(arr,n);
        t--;
    }



    
    

}



