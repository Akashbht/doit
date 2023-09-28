#include <iostream>
#include <string>

using namespace std;

class String {
private:
    string str;

public:
    String(string s) : str(s) {}

    String operator+(int num) {
        return String(to_string(num) + str);
    }

    void display() {
        cout << str << endl;
    }
};

int main() {
    string inputStr;
    cout << "Enter a string: ";
    cin >> inputStr;

    String myStr(inputStr);

    int num;
    cout << "Enter an integer: ";
    cin >> num;

    String result = myStr + num;

    cout << "Result: ";
    result.display();

    return 0;
}
