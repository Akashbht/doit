#include<stdio.h>
#include<stdlib.h>


struct singlenode{
    int data;
    struct singlenode* next;

};

void insertatbegin(struct singlenode** head, int val){
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

void printlist(struct singlenode** head){
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
};

   
void insertatindex(struct singlenode** head, int index, int val) {
    struct singlenode* temp = (struct singlenode*)malloc(sizeof(struct singlenode));
    temp->data = val;
    temp->next = NULL;
    if (!(*head)) {
        *head = temp;
        return;
    }
    if (index == 0) { 
        temp->next = *head;
        *head = temp;
        return;
    }
    struct singlenode* itr = *head;
    for (int i = 0; i < index - 1; i++) {
        itr = itr->next;
    }
    temp->next = itr->next; 
    itr->next = temp;
}




void insertatend(struct singlenode** head, int val){
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


void insertafter(struct singlenode** head,int k, int val){
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






int main(){
    struct singlenode* head = NULL;

    insertatbegin(&head,6);
    insertatbegin(&head,7);
    insertatbegin(&head,8);
    insertatbegin(&head,9);
    insertatend(&head,5);
    insertafter(&head,6,5.5);

    printlist(&head);
}
    