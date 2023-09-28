#include <stdio.h>
#include <stdlib.h>

struct singlenode {
    int data;
    struct singlenode* next;
};

void insertatbegincircularlylinked(struct singlenode** head, int val) {
    struct singlenode* temp = (struct singlenode*)malloc(sizeof(struct singlenode));
    temp->data = val;
    temp->next = *head;

    struct singlenode* last = *head;
    if (*head) {
        while (last->next != *head) {
            last = last->next;
        }
        last->next = temp;
    } else {
        temp->next = temp;
        *head = temp;
    }
}

void insertatendcircularlylinked(struct singlenode** head, int val) {
    struct singlenode* temp = (struct singlenode*)malloc(sizeof(struct singlenode));
    temp->data = val;
    temp->next = *head;

    struct singlenode* last = *head;
    if (*head) {
        while (last->next != *head) {
            last = last->next;
        }
        last->next = temp;
    } else {
        temp->next = temp;
        *head = temp;
    }
}

void insertaftercircularlylinked(struct singlenode** head, int k, int val) {
    struct singlenode* temp = (struct singlenode*)malloc(sizeof(struct singlenode));
    temp->data = val;

    struct singlenode* current = *head;
    if (!current) {
        printf("List is empty\n");
        return;
    }

    while (current->data != k && current->next != *head) {
        current = current->next;
    }

    if (current->data != k) {
        printf("Element %d not found\n", k);
        free(temp);
        return;
    }

    temp->next = current->next;
    current->next = temp;
}

void deletebegincircularlylinked(struct singlenode** head) {
    if (!(*head)) {
        printf("List is empty\n");
        return;
    }

    struct singlenode* temp = *head;
    struct singlenode* last = *head;

    while (last->next != *head) {
        last = last->next;
    }

    if (temp->next == temp) {
        *head = NULL;
    } else {
        *head = temp->next;
        last->next = *head;
    }

    free(temp);
}

void deleteendcircularlylinked(struct singlenode** head) {
    if (!(*head)) {
        printf("List is empty\n");
        return;
    }

    struct singlenode* current = *head;
    struct singlenode* prev = NULL;

    while (current->next != *head) {
        prev = current;
        current = current->next;
    }

    if (prev) {
        prev->next = *head;
    } else {
        *head = NULL;
    }

    free(current);
}

void deleteatkcircularlylinked(struct singlenode** head, int k) {
    if (!(*head)) {
        printf("List is empty\n");
        return;
    }

    struct singlenode* current = *head;
    struct singlenode* prev = NULL;

    while (current->data != k && current->next != *head) {
        prev = current;
        current = current->next;
    }

    if (current->data != k) {
        printf("Element %d not found\n", k);
        return;
    }

    if (current == *head) {
        deletebegincircularlylinked(head);
    } else {
        prev->next = current->next;
        free(current);
    }
}

void printlistcircularlylinked(struct singlenode** head) {
    if (!(*head)) {
        printf("List is empty\n");
        return;
    }

    struct singlenode* temp = *head;
    do {
        printf("%d ", temp->data);
        printf("\t");
        temp = temp->next;
    } while (temp != *head);
    printf("\n");
}

int main() {
    struct singlenode* head = NULL;
    int choice, val, k;

    printf("THIS IS A MENU DRIVEN PROGRAM :\n");
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert after a value\n");
        printf("4. Delete from the beginning\n");
        printf("5. Delete from the end\n");
        printf("6. Delete a node\n");
        printf("7. Print the list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at the beginning: ");
                scanf("%d", &val);
                insertatbegincircularlylinked(&head, val);
                break;
            case 2:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &val);
                insertatendcircularlylinked(&head, val);
                break;
            case 3:
                printf("Enter the value to insert after: ");
                scanf("%d", &k);
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                insertaftercircularlylinked(&head, k, val);
                break;
            case 4:
                deletebegincircularlylinked(&head);
                break;
            case 5:
                deleteendcircularlylinked(&head);
                break;
            case 6:
                printf("Enter the value to delete: ");
                scanf("%d", &k);
                deleteatkcircularlylinked(&head, k);
                break;
            case 7:
                printlistcircularlylinked(&head);
                break;
            case 8:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
