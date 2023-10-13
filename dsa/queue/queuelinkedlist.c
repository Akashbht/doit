#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node* next;
};

struct queue
{
    int size;
    struct node *front, *rear;
    

};

void initialise(struct queue* q){
    q-> size = 0;
    q->front = q->rear =  NULL;
}
struct node* createnode(int val){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = val;
    newnode ->next = NULL;
}

void enque(struct queue* q, int val){
    if(!(q->front)){
        printf("empty queue");
        q-> front = createnode(val);
        q->rear = q-> front;
        q->size++;
        printf("enqued :\n");
        return;
    }
    else{
        struct node* temp = createnode(val);
        q-> rear ->next = temp;
        q->rear = temp;
        q->size++;
        printf("enqued : \n");
        free(temp);
        
    }
}
void deque(struct queue* q){
    if(!(q->front)){
        printf("queue underflow : \n");
        return ;
    }
    struct node* temp = q -> front;
    q->front = q->front -> next;
    free(temp);
    q->size--;
    printf("Dequed :\n");
    return;
}
int top(struct queue* q){
    if(!q->front){
        printf("queue underflow;;\n");
        return 0;
    }
    return q->rear->data;
}
void print(struct queue* q){
    if(!(q->front)){
        printf("queue underflow ;; \n");
        return; 
    }
    struct node* itr = q-> front;
    
    while ( itr != NULL){
        printf("%d\t", itr->data);
        itr = itr->next;
    }
    printf("\n");
}
int main() {
    struct queue* q1;
    q1 = (struct queue*)malloc(sizeof(struct queue));
    for(int i=0;i<10;i++){
        enque(q1,i);
    }
    print(q1);
    enque(q1,6);
    print(q1);
    deque(q1);
    print(q1);

	return 0;
}