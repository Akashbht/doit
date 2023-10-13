#include<iostream>
#include<string>
using namespace std;
class STR
{
    private:
    string str;
    int num;
    string result;
    public:
    STR(){};
    STR(string s,int n)
    {
        s=str;
        num=n;
    }
    STR operator+()
    {
        string y;
        y.str=str;
        y.result=str+to_string(num);
        return y;
    }
    void display()
    {
        cout<<result<<" "<<endl;
    }
};
int main()
{
    string str="hello";
    int num=12;
    STR obj1(str,num),obj2;
    obj2=+obj1;
    obj2.display();
    return 0;
}