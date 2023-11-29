#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node *next;
};
struct node* newnode(int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = data;
    temp-> next = NULL;
    return temp;

}
void insert(struct node** head, int data){
    struct node* temp = newnode(data);
    if(!(*head)){
        (*head) = temp;
        return ;
    }
    temp -> next = (*head);
    (*head)=temp;
    return;
    
}


void printlist(struct node* head) {
    
    if (!head) {
        printf("List is empty\n");
        return;
    }

    struct node* itr = head;
    struct node* new = NULL;
    
    while(itr){
        if(!new){
            new = newnode(itr->data);
            itr = itr->next;
        }
        else{
            insert(&new,itr->data);
            itr = itr->next;
        }
    }  
    while (new != NULL) {
        printf("%d\t", new->data);
        new = new->next;
    }
    printf("\n");
}

struct node* reverse(struct node* head) {
    struct node* prev = NULL;
    struct node* current = head;
    struct node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

struct node* getmid(struct node* head){
    struct node* p1 = head, *p2 = head;
    while(p2 && p2-> next){
        p2= p2->next->next;
        p1 = p1->next;
    }
    return p1;
}
void altervalue(struct node** head, struct node* mid){
    struct node* itr = (*head), *itr2 = (*head)->next,* midnext = (mid->next);
    while(mid){
        itr -> next = mid;
        itr = itr->next;
    }
    
}


int main(void) {
    struct node* head = NULL;
    insert(&head,1);
    for(int i = 2; i < 11;i++ ){
        insert(&head,i);
    }
    printlist(head);


    // altervalue(&head);
	printlist(head);			
	return 0;
}