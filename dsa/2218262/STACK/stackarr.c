#include <stdio.h>
#include<stdlib.h>



struct arrstack {
    int *arr;
    int capacity, size, top;
};


void pusharr(struct arrstack *s1, int val) {
    if (s1->size == s1->capacity) {
        printf("Stack Overflow\n");
        return;
    }
    s1->top++;
    s1->arr[s1->top] = val;
    s1->size++;
}
int sizearr(struct arrstack* s1){
    if (s1->top == -1) {
        printf("empty stack\n");
        return -1;
    }
    return s1->size;
}

int poparr(struct arrstack *s1) {
    if (s1->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    int val = s1->arr[s1->top];
    s1->top--;
    s1->size--;
    return val;
}

void printstackarr(struct arrstack *s1) {
    if (s1->top == -1) {
        printf("Empty Stack\n");
        return;
    }
    for (int i = 0; i <= s1->top; i++) {
        printf("%d\t", s1->arr[i]);
    }
    printf("\n");
}

int toparr(struct arrstack *s1) {
    if (s1->top == -1) {
        printf("Empty Stack\n");
        return -1;
    }
    int top = s1->arr[s1->top];
    return top;
}

void initialisearr(struct arrstack *s1, int cap) {
    s1->capacity = cap;
    s1->size = 0;
    s1->top = -1;
    s1->arr = (int *)malloc(sizeof(int) * cap);
}


int main(){

    struct arrstack s1;
    
    int choice,val;
    printf("Enter the capacity of arrstack : \n");
                    int cap;
                    scanf("%d",&cap);
                    initialisearr(&s1,cap);
                    while (1) {
                        
                        printf("Enter 1 for PUSH : \n");
                        printf("Enter 2 for POP : \n");
                        printf("Enter 3 for TOP : \n");
                        printf("Enter 4 to PRINT STACK : \n");
                        printf("Enter 5 to SIZE : \n");
                        printf("Enter 6 to Exit : \n");
                        scanf("%d",&choice);
                        switch (choice)
                        {
                        case 1:
                            printf("Enter the value to push :");
                            scanf("%d",&val);
                            pusharr(&s1,val);
                            break; 
                        case 2:
                        
                            printf("\n");    
                            int poppedvalue = poparr(&s1);
                            printf("popped value : %d \n",poppedvalue);
                            break; 
                            
                        
                        case 3:
                            printf("\n");
                            int top = toparr(&s1);
                            printf("TOP of the stack is : %d \n", top);
                            break; 
                        case 4:
                            printstackarr(&s1);
                            break; 
                        case 5:
                            printf("\n");
                            int size = sizearr(&s1);
                            printf("\n");
                            printf("Size of stack is %d \n\n",size);
                            break;
                        case 6:
                            return 0;
                        default:
                            printf("\n\n invalid choice , try again : \n\n");
                        
                        
                        
                        
                    
        }
}       
}