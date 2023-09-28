#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node* next;

};

void insertatbegin(struct node** head, int val){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=NULL;
    if (!head){
        *head = temp;
        return;
    }
    temp -> next=(*head);
    (*head) = temp;
    
};

void printlist(struct node** head){
    if(!head){
        printf("List is empty\n");
        return;
    }
    struct node* itr = (*head);
    while(itr!= NULL ){
        

        printf("%d ",itr->data );
        printf("\t");
        itr = itr->next;
        
    }
};




void insertatend(struct node** head, int val){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=NULL;
    if (!head){
        *head = temp;
        return;
    }
    struct node* itr =  *head;
    while(itr->next){
        itr = itr -> next;
    }
    itr->next = temp;

};


void insertafter(struct node** head,int k, int val){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=NULL;
    if (!head){
        *head = temp;
        return;
    }
    struct node* itr =  *head;
    while(itr->data!=k && (itr->next)){
        itr = itr -> next;
    }
    temp->next = itr->next;
    itr->next = temp;

};






int main(){
    struct node* head = NULL;

    insertatbegin(&head,6);
    insertatbegin(&head,7);
    insertatbegin(&head,8);
    insertatbegin(&head,9);
    insertatend(&head,5);
    insertafter(&head,6,5.5);

    printlist(&head);
}
    