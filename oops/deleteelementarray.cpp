#include <iostream>
using namespace std;

int main() {
    const int maxSize = 100;
    int arr[maxSize];
    int size, elementToDelete;

    cout << "Enter the size of the array: ";
    cin >> size;

    if (size <= 0 || size > maxSize) {
        cout << "Invalid array size.\n";
        return 1;
    }

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Enter element";
    cin >> elementToDelete;

    bool found = false;
    int newSize = 0;


    for (int i = 0; i < size; i++) {
        if (arr[i] == elementToDelete) {
            found = true;
        } else {
            arr[newSize++] = arr[i];
        }
    }

    if (found) {
        cout <<elementToDelete << " deleted.\n";
    } else {
        cout << elementToDelete << " not found in the array.\n";
    }

    cout << "Updated array: ";
    for (int i = 0; i < newSize; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}
