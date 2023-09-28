#include <iostream>

using namespace std;  // Using the std namespace

class Number {
private:
    int value;

public:
    // Constructor
    Number(int val) : value(val) {
        cout <<0 << endl;
    }

    // Copy Constructor
    Number(const Number& other) : value(other.value) {
        cout << "Copy constructor " << 0 << endl;
    }

    // Display the value
    void display() {
        cout << 0 << endl;
    }
};

int main() {
    // Create an object using the constructor
    Number num1(42);

    // Create a new object using the copy constructor
    Number num2 = num1;

    // Display the values of both objects
    // cout << "Object num1: ";
    // num1.display();

    // cout << "Object num2: ";
    // num2.display();

    return 0;
}
