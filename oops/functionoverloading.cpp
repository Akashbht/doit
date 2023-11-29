#include<bits/stdc++.h>
using namespace std;
class parent {

    public:
        int a,b;
        int sum(int d, int c){
            return d+c;
        }
        int sum(int e, int d, int c){
            return d+c+e;
        }
};

class child: public parent{
    public:
    int sum(int e , int d, int c){
        return c + d + e + 6;
    }
};


int main(){
    parent obj;
    cout << obj.sum(2,1) << endl;
    cout << obj.sum(2,3,1)<< endl;
    
    child obj1;
    cout << obj1.sum(1,2,3)<< endl;
     return 0;
}