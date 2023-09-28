#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev; 
};

void printlist(struct node** head) {
    if (!head || !(*head)) {
        printf("List is empty\n");
        return;
    }
    struct node* itr = (*head);
    while (itr != NULL) {
        printf("%d ", itr->data);
        printf("\t");
        itr = itr->next;
    }
    printf("\n");
}

struct node* createnode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("allocation failed\n");
        return NULL;
    }
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void deletebegin(struct node** head) {
    if (!head || !(*head)) {
        printf("List is empty\n");
        return;
    }
    struct node* temp = *head;
    *head = (*head)->next;
    if (*head) {
        (*head)->prev = NULL;
    }
    free(temp);
}

void deleteend(struct node** head) {
    if (!head || !(*head)) {
        printf("List is empty\n");
        return;
    }
    struct node* itr = (*head);
    while (itr->next != NULL) {
        itr = itr->next;
    }
    if (itr->prev) {
        itr->prev->next = NULL;
    } else {
        *head = NULL;
    }
    free(itr);
}

void deleteatk(struct node** head, int k) {
    if (!head || !(*head)) {
        printf("List is empty\n");
        return;
    }
    struct node* itr = (*head);
    while (itr != NULL && itr->data != k) {
        itr = itr->next;
    }
    if (!itr) {
        printf("Element %d not found\n", k);
        return;
    }
    if (itr->prev) {
        itr->prev->next = itr->next;
    } else {
        *head = itr->next;
    }
    if (itr->next) {
        itr->next->prev = itr->prev;
    }
    free(itr);
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
