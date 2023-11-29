#include <stdio.h>
#include <stdlib.h>

// Write a C program to create two link lists positive and negative from Original linked list, so that
// positive linked list contains all positive elements and negative linked list contains negative elements.
// Positive and negative linked lists should use the node of existing original linked list.


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

int main(void) {
	struct node* head = NULL;
    insert(&head,1);
    for(int i = 2; i < 11;i++ ){
        if(i%2==0){
            insert(&head,-i);
        }
        else   insert(&head,i); 
        
    }

    printlist(head);
    
    struct node*pos = NULL, *neg = NULL,*poshead = NULL,*neghead = NULL, *itr = head;
    while(itr){
        if(itr -> data >= 0){
            if(!poshead){
                poshead = itr;
                pos = poshead;
            }else{
                pos -> next = itr;
                pos = pos-> next;
            } 

        }
        if(itr -> data < 0){
            if(!neghead){
                neghead= itr;
                neg= neghead;
            }else{
                neg-> next = itr;
                neg = neg-> next;
            } 

        }
        itr = itr->next;
    }
    if (pos) {
        pos->next = NULL;
    }
    if (neg) {
        neg->next = NULL;
    }
    printf("positive list : \n");
    printlist(poshead);


    printf("negative list : \n");
    printlist(neghead);
    
	return 0;
}