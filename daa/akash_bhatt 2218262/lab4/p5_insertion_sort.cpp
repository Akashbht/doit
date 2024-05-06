// given an unsorted array of integer , design an algo and program to sort the array using insertion sort. your program should be able to find number of comparisons and shift (shift is total number of times the array element are shifted from their places) required for sorting the array 


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
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
void print_arr(int*arr, int size){
    for(int i = 0;i<size;i++){
        cout << arr[i]<<" ";

    }
    cout<<endl;
}
void insertion_sort(int* arr, int size){
    int shifts = 0, comparisions = 0;
    for (int i=1; i<size; i++){
        int current = arr[i];
        int j = i-1;
        comparisions++;
        while (j>=0 && arr[j] > current ) {
            arr[j + 1] = arr[j];
            j--;
            shifts++;
        }
        arr[j + 1] = current;
    }
    cout << "Shifts: "<<shifts<<"\nComparisons:"<<comparisions<<endl;
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
        insertion_sort(arr,n);
        print_arr(arr,n);
        t--;
    }
}




