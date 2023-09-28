#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

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

struct node* createnode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("allocation failed\n");
        return NULL;
    }
    temp->data = data;
    temp->next = temp;
    temp->prev = temp;
    return temp;
}

void deletebegin(struct node** head) {
    if (!(*head)) {
        printf("list is empty\n");
        return;
    }
    struct node* temp = *head;
    if (temp->next == temp) {
        *head = NULL;
    } else {
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        *head = temp->next;
    }
    free(temp);
}

void deleteend(struct node** head) {
    if (!(*head)) {
        printf("list is empty\n");
        return;
    }
    struct node* temp = *head;
    if (temp->next == temp) {
        *head = NULL; 
    } else {
        temp = temp->prev;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    free(temp);
}

void deleteatk(struct node** head, int k) {
    if (!(*head)) {
        printf("list is empty\n");
        return;
    }
    struct node* temp = *head;
    while (temp->data != k && temp->next != (*head)) {
        temp = temp->next;
    }
    if (temp->data != k) {
        printf("Element %d not found \n", k);
        return;
    }
    if (temp->next == temp) {
        *head = NULL; 
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        if (temp == *head) {
            *head = temp->next;
        }
    }
    free(temp);
}

int main() {
    struct node* head = createnode(0);

    struct node* itr = head;
    for (int i = 1; i < 11; i++) {
        struct node* temp = createnode(i);
        temp->prev = itr;
        itr->next = temp;
        itr = itr->next;
    }

    printlist(&head);

    deletebegin(&head);
    printlist(&head);

    deleteend(&head);
    printlist(&head);

    deleteatk(&head, 6);
    printlist(&head);

    return 0;
}
