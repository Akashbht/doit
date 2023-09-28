#include <stdio.h>
#include<stdlib.h>

struct queue {
    int *arr;
    int capacity, front, rear,size;
};



struct queue* initialisequeue(int cap) {
    struct queue* temp = (struct queue*)malloc(sizeof(struct queue));
    temp->capacity=cap;

    temp->front = -1;
    temp->rear = -1;
    temp -> size = 0; 
    temp->arr = (int *)malloc(sizeof(int) * cap);
    return temp;
}

void enque(struct queue* q1, int value){
    if(q1->size == q1->capacity){
        printf("Queue is full\n");
        return ;
    }
    q1->arr[q1->rear] = value;
    q1->rear = (q1->rear + 1)% q1->capacity;
    
    q1->size++;

}

int deque(struct queue*q1){
    if(q1->size ==0){
        printf("empty queue");
        return 0;

    }
    int val = (q1->arr[q1->front]);
    q1-> front = (q1->front + 1)%q1->capacity;
    q1->size--;
    return val; 
}

void printqueue(struct queue* q1) {
    if (q1->size ==0) {
        printf("queue empty\n");
        return;
    }
    int i = q1->front;
    do {
        printf("%d ", q1->arr[i]);
        i = (i + 1) % q1->capacity; 
    } while (i != (q1->rear + 1) % q1->capacity);
    printf("\n");
}





int main(){

    
    int choice,val;
    printf("Enter the capacity of queue : \n");
                int cap;
                scanf("%d",&cap);
                struct queue* q1= initialisequeue(cap);
                while (1) {
                    
                    printf("Enter 1 for ENQUE : \n");
                    printf("Enter 2 for DEQUE : \n");
                    printf("Enter 3 for FRONT : \n");
                    printf("Enter 4 to SIZE : \n");
                    printf("Enter 5 to PRINT QUEUE : \n");
                    printf("Enter 6 to Exit : \n");
                    scanf("%d",&choice);
                    switch (choice)
                    {
                    case 1:
                        printf("Enter the value to push :");
                        scanf("%d",&val);
                        enque(q1,val);
                        break; 
                    case 2:
                    
                        printf("\n");    
                        int poppedvalue = deque(q1);
                        printf("popped value : %d \n",poppedvalue);
                        break; 
                        
                    
                    case 3:
                        printf("\n");
                        int top = q1->arr[q1->front];
                        printf("FRONT of the queue is : %d \n", top);
                        break; 
                    case 5:
                        printqueue(q1);
                        break; 
                    case 4:
                        printf("\n");
                        int size = (q1->size) + 1;
                        printf("\n");
                        printf("Size of queue is %d \n\n",size);
                        break;
                    case 6:
                        return 0;
                    default:
                        printf("\n\n invalid choice , try again : \n\n");
                    
                    
                    
                    
                    
                    }
                }





}