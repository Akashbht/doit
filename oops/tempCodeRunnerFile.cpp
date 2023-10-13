#include <iostream>
#include <string>

using namespace std;

// class String {
// private:
//     string str;
// // 
// public:
//     String(string s) {
//         str = s;
//     }

//     String operator+(int num) {
//         return String(to_string(num) + str);
//     }

//     void display() {
//         cout << str << endl;
//     }
// };

// int main() {
//     string inputStr;
//     cout << "Enter a string: ";
//     cin >> inputStr;

//     String myStr(inputStr);

//     int num;
//     cout << "Enter an integer: ";
//     cin >> num;

//     String result = myStr + num;

//     cout << "Result: ";
//     result.display();

//     return 0;
// }


class String{

    private:
    string str;
    int num;
    string resultedoutput;
    public:
    String(){};
    String(string s,int n){
        str= s;
num = n;
   }

    String operator+(){
        String y;
       y.str = str;
       y.resultedoutput = str + to_string(num);
       return y;
    
    }
    void display(){
        cout<<resultedoutput<<" "<<endl;}
};
int main(){
    string str = "hellop";
    int n = 7;
    String obj1(str,n),obj2;
    obj2 = +obj1;//invoke operator overloading
    obj2.display();
return 0;
}


// class STR{
//     private:
//     string str;
//     public:
//     STR(string s){
//         str = s;
//     };
//     STR operator+(int num){
//         return (str + to_string(num));
//     } 
//     void display(){
//         cout << str<<endl;
//     }
// };
// int main(){
//     string str = "hello";
//     STR obj1 = str;
//     STR obj2 = obj1+5;
//     obj2.display();
// }