#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
void insertend(struct node** head, int data) {
    struct node* newnode = createnode(data);
    if (*head == NULL) {
        *head = newnode;
    } else {
        struct node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
struct node* mergealternate(struct node* A, struct node* B) {
    struct node* S = NULL;

    while (A != NULL || B != NULL) {
        if (A != NULL) {
            insertend(&S, A->data);
            A = A->next;
        }
        if (B != NULL) {
            insertend(&S, B->data);
            B = B->next;
        }
    }

    return S;
}
void display(struct node* head) {
    while (head != NULL) {
        printf("%d   ", head->data);
        head = head->next;
    }
    printf("\n");
}


int main() {
    struct node* A = NULL;
    int i = 0;
    printf("enter elements for List A:(-1 to exit)");
    while(i!= -1){
        scanf("%d", &i);
        insertend(&A,i);
    }
    struct node* B = NULL;
    i = 0; 
    printf("enter elements for List B:(-1 to exit)");
    while(i!= -1){
        scanf("%d", &i);
        insertend(&B,i);
    }
    struct node* S = mergealternate(A, B);

    printf("Linked List A: /\n");
    display(A);

    printf("Linked List B: /\n");
    display(B);

    printf("Merged Linked List S: \n");
    display(S);
    return 0;
}
