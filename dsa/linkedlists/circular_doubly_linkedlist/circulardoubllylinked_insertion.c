#include <stdio.h>
#include <stdlib.h>

struct doublenode {
    int data;
    struct doublenode* next;
    struct doublenode* prev;
};

void insertatbegincircularlylinked(struct doublenode** head, int val) {
    struct doublenode* temp = (struct doublenode*)malloc(sizeof(struct doublenode));
    temp->data = val;
    if (!(*head)) {
        temp->next = temp; 
        temp->prev = temp; 
    } else {
        temp->next = *head;
        temp->prev = (*head)->prev;
        (*head)->prev->next = temp;
        (*head)->prev = temp;
    }
    *head = temp;
}

void printlistcircularlylinked(struct doublenode** head) {
    if (!(*head)) {
        printf("List is empty\n");
        return;
    }
    struct doublenode* itr = (*head);
    do {
        printf("%d ", itr->data);
        printf("\t");
        itr = itr->next;
    } while (itr != (*head)); 
    printf("\n");
}

void insertatendcircularlylinked(struct doublenode** head, int val) {
    struct doublenode* temp = (struct doublenode*)malloc(sizeof(struct doublenode));
    temp->data = val;
    if (!(*head)) {
        temp->next = temp; 
        temp->prev = temp; 
        *head = temp;
        return;
    }
    struct doublenode* last = (*head)->prev; 
    temp->next = *head;
    temp->prev = last;
    last->next = temp;
    (*head)->prev = temp;
}

void insertaftercircularlylinked(struct doublenode** head, int k, int val) {
    struct doublenode* temp = (struct doublenode*)malloc(sizeof(struct doublenode));
    temp->data = val;
    if (!(*head)) {
        printf("List is empty\n");
        return;
    }
    struct doublenode* itr = *head;
    while (itr->data != k && itr->next != (*head)) {
        itr = itr->next;
    }
    temp->next = itr->next;
    temp->prev = itr;
    itr->next->prev = temp;
    itr->next = temp;
}

int main() {
    struct doublenode* head = NULL;

    insertatbegincircularlylinked(&head, 6);
    insertatbegincircularlylinked(&head, 7);
    insertatbegincircularlylinked(&head, 8);
    insertatbegincircularlylinked(&head, 9);
    insertatendcircularlylinked(&head, 5);
    insertaftercircularlylinked(&head, 6, 5); 
    insertatendcircularlylinked(&head,4);
    printlistcircularlylinked(&head);

    return 0;
}
