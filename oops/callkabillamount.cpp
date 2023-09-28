#include<iostream>
using namespace std;

class telcall {
private:
    int phno;
    string sname;
    int n;
    double amt;

public:
    telcall(int a, string b, int c, double d) {
        phno = a;
        sname = b;
        n = c;
        amt = d;
    };

    
    void compute() {
        if (n <= 100)
            amt = 500;
        else if (n <= 200)
            amt = 500 + (n - 100) * 1.00;
        else if(n<=300)
            amt = 500 + 100 + (n - 200) * 1.20;
        else
            amt = 500 + 100 + 120 + (n-300) * 1.50;
    }


    
    void display() {
        cout << "Number: " << phno << endl;
        cout << "Name: " << sname << endl;
        cout << "Number of Calls: " << n << endl;
        cout << "Amount: " << amt << endl;
    }
};

int main() {
    long int number = 12345678;
    string name = "XYZ";
    int calls = 315;
    double amount = 0.0;

    telcall bill(number, name, calls, amount);

    bill.compute(); 
    bill.display(); 

    return 0;
}
