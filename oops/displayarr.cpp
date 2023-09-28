#include <iostream>
using namespace std;

void displayarr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    const int size = 5;
    int arr[size] = {10, 20, 30, 40, 50};

    cout << "Array elements : "<<endl;
    displayarr(arr, size);

    return 0;
}
