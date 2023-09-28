#include<stdio.h>


int factorial( int n){
    if (n==0) return 1;
    return n*factorial(n-1);

}
int main(){
    int a;
    printf("enter the no. :");
    scanf("%d", &a);
    printf("%d",factorial(a));
}