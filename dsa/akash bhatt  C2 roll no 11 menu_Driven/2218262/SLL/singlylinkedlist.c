#include <stdio.h>
#include<stdlib.h>



struct singlenode{
    int data;
    struct singlenode* next;

};




void insertatbeginsinglylinked(struct singlenode** head, int val){
    struct singlenode* temp = (struct singlenode*)malloc(sizeof(struct singlenode));
    
    temp->data=val;
    temp->next=NULL;
    if (!head){
        
        *head = temp;
        return;
    }
    temp -> next=(*head);
    (*head) = temp;
    
    
};

void insertatendsinglylinked(struct singlenode** head, int val){
    struct singlenode* temp = (struct singlenode*)malloc(sizeof(struct singlenode));
    temp->data=val;
    temp->next=NULL;
    if (!head){
        *head = temp;
        return;
    }
    struct singlenode* itr =  *head;
    while(itr->next){
        itr = itr -> next;
    }
    itr->next = temp;

};

void insertaftersinglylinked(struct singlenode** head,int k, int val){
    struct singlenode* temp = (struct singlenode*)malloc(sizeof(struct singlenode));
    temp->data=val;
    temp->next=NULL;
    if (!head){
        *head = temp;
        return;
    }
    struct singlenode* itr =  *head;
    while(itr->data!=k && (itr->next)){
        itr = itr -> next;
    }
    temp->next = itr->next;
    itr->next = temp;

};


void printlistsinglylinked(struct singlenode** head){
    printf("\n\n");
    if(!head){
        printf("List is empty\n");
        return;
    }
    struct singlenode* itr = (*head);
    while(itr!= NULL ){
        

        printf("%d ",itr->data );
        printf("\t");
        itr = itr->next;
        
    }
    printf("\n\n");
};


void deletebeginsinglylinked(struct singlenode** head){
    if((*head)==NULL ||(*head)->next==NULL ){
        (*head) = NULL;
        return;
    }
    (*head) = (*head)-> next;
    return;
}

void deleteatksinglylinked(struct singlenode** head, int k){
    if((*head)==NULL ||(*head)->next==NULL ){
        (*head) = NULL;
        return;
    }
    struct singlenode* itr = (*head);
    while((itr -> next )-> data != k ){
        itr = itr -> next;
    }
    itr->next = itr ->next -> next;
    return;
}


void deleteendsinglylinked(struct singlenode** head){
    if((*head)==NULL ||(*head)->next==NULL ){
        (*head) = NULL;
        return;
    }
    struct singlenode* itr = (*head);
    while(((itr -> next )-> next ) !=NULL){
        itr = itr -> next;
    }
    itr->next = NULL;
    return;
}



int main(){

    struct singlenode* head = NULL;

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
                                insertatbeginsinglylinked(&head, val);
                                break;

                            case 2:
                                printf("Enter the value to insert: ");
                                scanf("%d", &val);
                                insertatendsinglylinked(&head, val);
                                break;

                            case 3:
                                printf("Enter the value to insert after: ");
                                int k;
                                scanf("%d", &k);
                                printf("Enter the value to insert: ");
                                scanf("%d", &val);
                                insertaftersinglylinked(&head, k, val);
                                break;

                            case 4:
                                deletebeginsinglylinked(&head);
                                break;

                            case 5:
                                deleteendsinglylinked(&head);
                                break;

                            case 6:
                                printf("Enter the value to delete: ");
                                scanf("%d", &k);
                                deleteatksinglylinked(&head, k);
                                break;

                            case 7:
                                printlistsinglylinked(&head);
                                break;

                            case 8:
                                return 0;

                            default:
                                printf("Invalid choice, Please try again\n");
                        }
                    }


}