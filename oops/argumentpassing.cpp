#include<iostream>
using namespace std;


// the inline funtion replaces the func code in the main func
inline int add(int a, int b){
    return a+b;
    }

// default argument 
// restriction 1-> always give default argument to trailing parameters otherwise error generated  
// restriction 2-> once a default argument is given in a declaration or defition, you cannot redefine that argument, even to the same value. 
// 				however you can add default arguments not given in previous declarations
/*		void float(int a, int b, int c = 1);
		void float(int a, int b = 1 , int c);					funtion already declared hence no error	
		void float(int a = 1, int b, int c);					no error
		void float(int a = 1, int b = 1, int c = 1);			error cause redefining argument 
*/ 
int sum (int x, int y, int z = 0, int w = 0){
	return(x+y+z+w);
}

int main(){

    /*// 1 -09-23
    //argument passing


    1. Call by value 
    2. Call by address(reference)





    */

  //  1. CALL BY VALUE::
/*
    int a,b;
    a = 5;
    b = 15;
    cout << add(a,b) << endl;
  */



 // INLINE FUNCTION  
	// add inline in front of the function 
	// switches the func code in the inline 
/*
	int a,b;
	a = 10;
	b = 20;
	int sum = add(a,b);
	cout<<"the output of inline function us "<<sum<<endl;
	return 1;
*/

/*   1. C++ compiler is responsible for substituting the function code at the place of funtion call
	2.	to minimise switching overhead
	3. to make funtion execution more efficient 
	4. good for small size( logic function )
 
 */


// DEFAULT ARGUMENT 
	int x = 10 ,y = 20,z = 30,w = 40;
	
	cout << sum(x,y)<<endl;
	cout<< sum(x,y,w)<<endl;
	cout << sum(x,y,z,w)<<endl;
		


    


   
    


















  return 0;
}