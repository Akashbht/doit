#include<stdio.h>

void toh(int n, char s, char a, char d){
    if(n==0)return;
    toh(n-1 ,s,d,a);
    printf("Move disk %d from rod %c to rod %c\n",n,s,d );
    toh(n-1,a,s,d);

}

int main() {
    toh(2,'A','B', 'C');


}