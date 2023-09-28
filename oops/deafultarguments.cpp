#include<iostream>
using namespace std;


// default argument 
// restriction 1-> always give default argument to trailing parameters otherwise error generated  
// restriction 2-> once a default argument is given in a declaration or defition, you cannot redefine that argument, even to the same value. 
// 				however you can add default arguments not given in previous declarations


//  we cannot pass second pass element as first as funtion would map its elements from start to end


/*		void float(int a, int b, int c = 1);
		void float(int a, int b = 1 , int c);					funtion already declared hence no error	
		void float(int a = 1, int b, int c);					no error
		void float(int a = 1, int b = 1, int c = 1);			error cause redefining argument 
*/ 
int sum (int x, int y, int z = 0, int w = 0){
	return(x+y+z+w);
}


void add1(int a = 1, float b = 1.2){
    cout <<"a:" << a<< endl;
    cout <<"b:" << b<< endl;

    // printf("%d",b);

}
int main(){
// DEFAULT ARGUMENT 
	int x = 10 ,y = 20,z = 30,w = 40;
	
	// cout << sum(x,y)<<endl;
	// cout<< sum(x,y,w)<<endl;
	// cout << sum(x,y,z,w)<<endl;

    // add1(2.6);          
    // add1(2.7, 2.7);
    add1(2, 2);
    // add1(2);


return 0;
}