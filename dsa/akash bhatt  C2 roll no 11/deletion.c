#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node* next;

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
    printf("\n");
};

//a func to return the node 
struct node* createnode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return 0;
    }       
    temp->data = data;                               
    temp->next = NULL;                           
    return temp;
}


void deletebegin(struct node** head){
    if((*head)==NULL ||(*head)->next==NULL ){
        (*head) = NULL;
        return;
    }
    (*head) = (*head)-> next;
    return;
}


void deleteend(struct node** head){
    if((*head)==NULL ||(*head)->next==NULL ){
        (*head) = NULL;
        return;
    }
    struct node* itr = (*head);
    while(((itr -> next )-> next ) !=NULL){
        itr = itr -> next;
    }
    itr->next = NULL;
    return;
}



void deleteatk(struct node** head, int k){
    if((*head)==NULL ||(*head)->next==NULL ){
        (*head) = NULL;
        return;
    }
    struct node* itr = (*head);
    while((itr -> next )-> data != k ){
        itr = itr -> next;
    }
    itr->next = itr ->next -> next;
    return;
}



int main(){
    struct node* head = createnode(0);
    
    
    struct node* itr = head; 
    for(int i=1;i<11;i++) {
        itr -> next = createnode(i);
        itr = itr-> next;
    }
    itr -> next = NULL;
    
    printlist(&head);


    // start deleting element
    deletebegin(&head);
    printlist(&head);

    deleteend(&head);
    printlist(&head);

    deleteatk(&head,6);
    printlist(&head);
}