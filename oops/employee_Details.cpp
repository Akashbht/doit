#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    string name;
    int age;
    int salary;

public:
    Employee(string n, int a, int s) {
        name = n;
        age = a;
        salary = s;
    }
    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    Employee obj("Sumit", 28, 60000);
    obj.display();

    return 0;
}
