//   given an unsorted array of alphabets containing duplilcate elements, design an algo and implement if using the program to find which alphabet as maximum no. of occurance and print it 
//  time complexity - O(n)


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char findMaxOccurrence(char* arr, int n) {
    vector<int> hash(26, 0);  
    for (int i = 0; i < n; i++) {
        hash[arr[i] - 'a']++;  
    }
    int maxOccurrence = 0;
    char maxChar = 'a';  
    for (int i = 0; i < 26; i++) {
        if (hash[i] > maxOccurrence) {
            maxOccurrence = hash[i];
            maxChar = 'a' + i; 
        }
    }
    return maxChar;
}

int main() {
    char arr[] = {'a', 'a', 'b', 'c', 'c', 'c', 'd', 'd', 'd', 'd'};
    int n = 10;
    cout << "The alphabet with maximum occurrences is: " << findMaxOccurrence(arr, n) << endl;
    return 0;
}