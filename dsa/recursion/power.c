#include<stdio.h>

int power(int n){
    if (n==0){
        return 1;
    }
    int choti = power(n-1);
    int badi = 2 * choti;
    return badi; 
}   


int main(){
    int a = power(10);
    printf("%d", a);
} 