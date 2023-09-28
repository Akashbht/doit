#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct queue {
    struct node* front;
    struct node* rear;
    int size;
};

struct queue* initialiseQueue() {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

void enqueue(struct queue* q, int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    q->size++;
}

int dequeue(struct queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    int value = q->front->data;
    struct node* temp = q->front;

    if (q->front == q->rear) {
        q->front = NULL;
        q->rear = NULL;
    } else {
        q->front = q->front->next;
    }

    free(temp);
    q->size--;
    return value;
}

int front(struct queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    return q->front->data;
}

int size(struct queue* q) {
    return q->size;
}

void printQueue(struct queue* q) {
    struct node* current = q->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct queue* q = initialiseQueue();
    int choice, val;

    printf("Enter the capacity of queue: \n");
    int cap;
    scanf("%d", &cap);

    while (1) {
        printf("Enter 1 to ENQUEUE:\n");
        printf("Enter 2 to DEQUEUE:\n");
        printf("Enter 3 to FRONT:\n");
        printf("Enter 4 to SIZE:\n");
        printf("Enter 5 to PRINT QUEUE:\n");
        printf("Enter 6 to EXIT:\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &val);
                enqueue(q, val);
                break;
            case 2:
                printf("\n");
                int poppedValue = dequeue(q);
                if (poppedValue != -1) {
                    printf("Dequeued value: %d\n", poppedValue);
                }
                break;
            case 3:
                printf("\n");
                int frontValue = front(q);
                if (frontValue != -1) {
                    printf("Front of the queue is: %d\n", frontValue);
                }
                break;
            case 4:
                printf("\n");
                int queueSize = size(q);
                printf("Size of queue is %d\n\n", queueSize);
                break;
            case 5:
                printQueue(q);
                break;
            case 6:
                return 0;
            default:
                printf("\nInvalid choice, try again:\n");
        }
    }

    return 0;
}
