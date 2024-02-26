#include<iostream>
using namespace std;

bool linearsearch(int * arr,int size, int value){
    if(size == -1){
        return false;
    }
    if(arr[size-1]==value){
        return true;
    }
    else{
        return linearsearch(arr,size-1,value);
    }

    

    // int i = 0;
    // while(i<size){
    //     if(arr[i]==value){
    //         return true;
    //     }
    //     i++;
    // }
    // return false;


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



