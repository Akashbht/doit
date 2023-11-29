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

struct node* subtract(struct node* num1, struct node* num2) {
    // printf("subtraction called");
    int borrow = 0, diff = 0;
    struct node* result = NULL, *itr;
    
    while (num1 || num2) {
        diff = borrow;

        if (num1) {
            diff += num1->data;
            num1 = num1->next;
        }

        if (num2) {
            diff -= num2->data;
            num2 = num2->next;
        }

        if (diff < 0) {
            borrow = -1;
            diff += 10;
        } else {
            borrow = 0;
        }

        struct node* newNode = newnode(diff);

        if (!result) {
            result = newNode;
            itr = result;
        } else {
            itr->next = newNode;
            itr = itr->next;
        }
    }

    return result;
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

int main() {
    
    struct node* p1= newnode(8);
    insert(&p1,9);
    insert(&p1,7);
    // insert(&p1,7);
    // insert(&p1,5);
    // insert(&p1,5);

    
    printlist(p1);


    struct node* p2= newnode(1);
    insert(&p2,4);    
    insert(&p2,5);
    
    printlist(p2);

    printf("subtract\n");
    struct node* sub = subtract(p1,p2);
    printlist(sub);

}