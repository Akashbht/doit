
#include <stdio.h>
#include<stdlib.h>



struct doublenode {
    int data;
    struct doublenode* next;
    struct doublenode* prev;
};



void insertatbegindoublylinked(struct doublenode** head, int val) {
    struct doublenode* temp = (struct doublenode*)malloc(sizeof(struct doublenode));
    temp->data = val;
    temp->prev = NULL;
    if (!(*head)) {
        temp->next = NULL; 
    } else {
        temp->next = *head;
        (*head)->prev = temp;
    }
    *head = temp;
}

void printlistdoublylinked(struct doublenode** head){
    if(!(*head)){
        printf("List is empty\n");
        return;
    }
    struct doublenode* itr = (*head);
    while(itr!= NULL ){
        

        printf("%d ",itr->data );
        printf("\t");
        itr = itr->next;
        
    }
};




void insertatenddoublylinked(struct doublenode** head, int val) {
    struct doublenode* temp = (struct doublenode*)malloc(sizeof(struct doublenode));
    temp->data = val;
    temp->next = NULL;
    if (!(*head)) {
        temp->prev = NULL; 
        *head = temp;
        return;
    }
    struct doublenode* itr = *head;
    while (itr->next) {
        itr = itr->next;
    }
    itr->next = temp;
    temp->prev = itr;
}


void insertafterdoublylinked(struct doublenode** head, int k, int val) {
    struct doublenode* temp = (struct doublenode*)malloc(sizeof(struct doublenode));
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;
    if (!(*head)) {
        printf("List is empty\n");
        return;
    }
    struct doublenode* itr = *head;
    while (itr->data != k && itr->next) {
        itr = itr->next;
    }
    temp->next = itr->next;
    temp->prev = itr;
    if (itr->next) {
        itr->next->prev = temp;
    }
    itr->next = temp;
}





struct doublenode* createdoublenode(int data) {
    struct doublenode* temp = (struct doublenode*)malloc(sizeof(struct doublenode));
    if (temp == NULL) {
        printf("allocation failed\n");
        return NULL;
    }
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void deletebegindoublylinked(struct doublenode** head) {
    if (!head || !(*head)) {
        printf("List is empty\n");
        return;
    }
    struct doublenode* temp = *head;
    *head = (*head)->next;
    if (*head) {
        (*head)->prev = NULL;
    }
    free(temp);
}

void deleteenddoublylinked(struct doublenode** head) {
    if (!head || !(*head)) {
        printf("List is empty\n");
        return;
    }
    struct doublenode* itr = (*head);
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

void deleteatkdoublylinked(struct doublenode** head, int k) {
    if (!head || !(*head)) {
        printf("List is empty\n");
        return;
    }
    struct doublenode* itr = (*head);
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





int main(){

    struct doublenode* dhead = NULL;
    int choice,val;



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
                    insertatbegindoublylinked(&dhead, val);
                    break;
            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                insertatenddoublylinked(&dhead, val);
                break;
            case 3:
                printf("Enter the value to insert after: ");
                int k;
                scanf("%d", &k);
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                insertafterdoublylinked(&dhead, k, val);
                break;
            case 4:
                deletebegindoublylinked(&dhead);
                break;
            case 5:
                deleteenddoublylinked(&dhead);
                break;
            case 6:
                printf("Enter the value to delete: ");
                scanf("%d", &k);
                deleteatkdoublylinked(&dhead, k);
                break;
            case 7:
                printlistdoublylinked(&dhead);
                break;
            case 8:
                return 0;
            default:
                printf("Invalid choice, Please try again\n");
        }
    }    


}
