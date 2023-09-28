#include<stdio.h>

int print(int n){
    if (n == 0) {
        return 1;
    }
    print(n-1);
    printf("%d \n",n);

    return 1;
}

// tail recurison


// int print(int n){
//     if (n == 0) {
//         return 1;
//     }
//     printf("%d \n",n);
//     print(n-1);

// }


int main(){
    int a = 9;
    print(a);

}