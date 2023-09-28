#include <stdio.h>
#include <stdlib.h>

struct doublenode {
    int data;
    struct doublenode* next;
    struct doublenode* prev;
};

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

struct doublenode* createdoublenodecircularlylinked(int data) {
    struct doublenode* temp = (struct doublenode*)malloc(sizeof(struct doublenode));
    if (temp == NULL) {
        printf("allocation failed\n");
        return NULL;
    }
    temp->data = data;
    temp->next = temp;
    temp->prev = temp;
    return temp;
}

void deletebegincircularlylinked(struct doublenode** head) {
    if (!(*head)) {
        printf("list is empty\n");
        return;
    }
    struct doublenode* temp = *head;
    if (temp->next == temp) {
        *head = NULL;
    } else {
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        *head = temp->next;
    }
    free(temp);
}

void deleteendcircularlylinked(struct doublenode** head) {
    if (!(*head)) {
        printf("list is empty\n");
        return;
    }
    struct doublenode* temp = *head;
    if (temp->next == temp) {
        *head = NULL; 
    } else {
        temp = temp->prev;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    free(temp);
}

void deleteatkcircularlylinked(struct doublenode** head, int k) {
    if (!(*head)) {
        printf("list is empty\n");
        return;
    }
    struct doublenode* temp = *head;
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
    struct doublenode* head = createdoublenode(0);

    struct doublenode* itr = head;
    for (int i = 1; i < 11; i++) {
        struct doublenode* temp = createdoublenode(i);
        temp->prev = itr;
        itr->next = temp;
        itr = itr->next;
    }

    printlistcircularlylinked(&head);

    deletebegincircularlylinked(&head);
    printlistcircularlylinked(&head);

    deleteendcircularlylinked(&head);
    printlistcircularlylinked(&head);

    deleteatkcircularlylinked(&head, 6);
    printlistcircularlylinked(&head);

    return 0;
}
