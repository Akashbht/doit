#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

void insertatbegin(struct node** head, int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
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

void printlist(struct node** head) {
    if (!(*head)) {
        printf("List is empty\n");
        return;
    }
    struct node* itr = (*head);
    do {
        printf("%d ", itr->data);
        printf("\t");
        itr = itr->next;
    } while (itr != (*head)); 
    printf("\n");
}

void insertatend(struct node** head, int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    if (!(*head)) {
        temp->next = temp; 
        temp->prev = temp; 
        *head = temp;
        return;
    }
    struct node* last = (*head)->prev; 
    temp->next = *head;
    temp->prev = last;
    last->next = temp;
    (*head)->prev = temp;
}

void insertafter(struct node** head, int k, int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    if (!(*head)) {
        printf("List is empty\n");
        return;
    }
    struct node* itr = *head;
    while (itr->data != k && itr->next != (*head)) {
        itr = itr->next;
    }
    temp->next = itr->next;
    temp->prev = itr;
    itr->next->prev = temp;
    itr->next = temp;
}

int main() {
    struct node* head = NULL;

    insertatbegin(&head, 6);
    insertatbegin(&head, 7);
    insertatbegin(&head, 8);
    insertatbegin(&head, 9);
    insertatend(&head, 5);
    insertafter(&head, 6, 5); 
    insertatend(&head,4);
    printlist(&head);

    return 0;
}
