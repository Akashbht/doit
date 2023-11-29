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

struct node* partitionlist(struct node* head, int v) {
    struct node* lesshead = NULL;
    struct node* lesstail = NULL;
    struct node* greaterhead = NULL;
    struct node* greatertail = NULL;

    while (head != NULL) {
        if (head->data < v) {
            if (lesshead == NULL) {
                lesshead = lesstail = head;
            } else {
                lesstail->next = head;
                lesstail = head;
            }
        } else {
            if (greaterhead == NULL) {
                greaterhead = greatertail = head;
            } else {
                greatertail->next = head;
                greatertail = head;
            }
        }
        head = head->next;
    }

    if (lesshead == NULL) {
        return greaterhead;
    } else {
        lesstail->next = greaterhead;
        if (greatertail != NULL) {
            greatertail->next = NULL;
        }
        return lesshead;
    }
}

void displaylist(struct node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL;
    int n, value;
    
    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);

    printf("Enter the elements of the linked list:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &value);
        insertend(&head, value);
    }

    printf("Original Linked List: ");
    displaylist(head);

    int v;
    printf("Enter the value V for partitioning: ");
    scanf("%d", &v);

    head = partitionlist(head, v);

    printf("Partitioned Linked List: ");
    displaylist(head);

    struct node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
