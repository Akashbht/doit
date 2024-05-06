void printarr(int arr[], int n ){
    int i = 0 ;
    while(i<n){
        cout << arr[i++] << " ";
    }
    cout<<endl;
}
void insertion_sort(int arr[], int n ){
    int shifts = 0, comparisons = 0;
    for (int i = 1 ; i < n ;i++){
        int key=arr[i] , j=i-1;
        shifts++;
        while (j >=0 && arr[j] >key) {
            arr[j+1]=arr[j];
            comparisons++;
            j--;
        }
        arr[j + 1 ] = key;
    }
    printarr(arr, n);
    cout<<"Shifts :"<<shifts<<endl;
    cout<<"Comparisons :"<<comparisons<<endl;

}
int main(){
    int n;
    cout<<"enter number of testcases : ";
    cin>> n;

    while(n){
        cout << "enter the size of array :";
    cin>> n;
    int arr[n];
    int i = 0;
    while(i<n){
        cout<<"enter element :";
        cin>> arr[i++];
    }
    printarr(arr,n);
    insertion_sort(arr,n);
    n--;
    }
    return 0;
}