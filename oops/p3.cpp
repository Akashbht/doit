#include <iostream>

using namespace std;

void hasPairWithSum(int arr[], int n, int x) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == x) {
                cout<< arr[i] << arr[j] << " pair found"<<endl;
            }
        }
    }
    return ;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;

    hasPairWithSum(arr ,n,n);

    return 0;
}
















