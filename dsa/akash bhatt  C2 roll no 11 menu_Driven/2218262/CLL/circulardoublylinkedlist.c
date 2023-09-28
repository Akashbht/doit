

#include <stdio.h>
#include<stdlib.h>


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

int main(){

    struct doublenode* dhead = NULL;
    int choice,val;

    printf("THIS IS A MENU DRIVEN PROGRAM :\n");
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert after a node\n");
        printf("4. Delete from the beginning\n");
        printf("5. Delete from the end\n");
        printf("6. Delete a node\n");
        printf("7. Print the list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                int val;
                scanf("%d", &val);
                insertatbegincircularlylinked(&dhead, val);
                break;
            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                insertatendcircularlylinked(&dhead, val);
                break;
            case 3:
                printf("Enter the value to insert after: ");
                int k;
                scanf("%d", &k);
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                insertaftercircularlylinked(&dhead, k, val);
                break;
            case 4:
                deletebegincircularlylinked(&dhead);
                break;
            case 5:
                deleteendcircularlylinked(&dhead);
                break;
            case 6:
                printf("Enter the value to delete: ");
                scanf("%d", &k);
                deleteatkcircularlylinked(&dhead, k);
                break;
            case 7:
                printlistcircularlylinked(&dhead);
                break;
            case 8:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

}

