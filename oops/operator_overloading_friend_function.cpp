

// opeator overloading using friend funtion 


// As we know that we can not access the private members of the class through object, but c++ provides a
//  feature through which we can access even the private members of a class as well
// this feature is called friend function . friend function can only be defined outside the class but not inside the class
//  friend function can be declared inside class
//  friend keyword is followed by function prototype
// it is not a member function



#include <iostream>
#include <string>

using namespace std;

class Box {
private:
    int length;

public:
    Box(){
        this->length = 10;

    }
    Box operator++(){
        Box obj;
        obj.length  = obj.length + 20;
        return obj;
    };
    Box operator++(int){
        obj.length = obj.length + 40;
        return obj.length;
    }
    int display(){
        return this->length;
    }
};

int main() {
    Box obj1;
    Box obj2 = ++obj1;
    cout<<"length "<< obj2.display()<<endl;

    Box obj3 = obj2++;
    cout <<"length :"<<obj3.display()<<endl;
}














