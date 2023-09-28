#include<stdio.h>
#include<stdlib.h>


struct poly{
    int data;
    struct poly* next;
};

struct poly* newnode(int data){
    struct poly* temp = (struct poly*)malloc(sizeof(struct poly));
    temp -> data = data;
    temp-> next = NULL;
    return temp;

}


void printlist(struct poly* head){
    if(!head){
        printf("List is empty\n");
        return;
    }
    struct poly* itr = head;
    while(itr!= NULL ){
        

        printf("%d ",itr->data );
        printf("\t");
        itr = itr->next;
        
    }
    printf("\n");
};


void insert(struct poly** head, int data){
    struct poly* temp = newnode(data);
    if(!(*head)){
        (*head) = temp;
        return ;
    }
    temp -> next = (*head);
    (*head)=temp;
    return;
    
}

int length(struct poly* head){
    int len = 0;
    while(head){
        len++;
        head = head-> next;
    }
    return len;
}

struct poly* addpoly(struct poly* p1, struct poly* p2){
    struct poly* res = NULL, *itr;
    int c1 = length(p1), c2 = length(p2);
    
    if(c1<c2){
        struct poly* temp = p1;
        p1 = p2;
        p2 = temp;
        int tempc = c1;
        c1 =  c2;
        c2  = tempc;

    }
    int difflength = c1 - c2, i =0 ;
    
    while(i<difflength){
        if(res == NULL){
            res = newnode(p1->data);
            itr = res;
            p1 = p1-> next;
        }
        else{
            itr -> next = newnode(p1->data);
            itr = itr->next;
            p1 = p1 -> next;
        }
        i++;
    }
    while(p1){
        if(!res){
            res = newnode(p1->data + p1->data);
            itr = res;
        }
        else {
            itr -> next = newnode(p1->data + p2->data);
            itr = itr -> next;

        }
        p1 = p1->next;
        p2 = p2-> next;


    }
    return res;


}


int main() {

    struct poly* p1= newnode(1);

    // printlist(p1);


    insert(&p1,2);
    insert(&p1,3);
    insert(&p1,4);
    insert(&p1,5);
    printlist(p1);


    struct poly* p2= newnode(2);
    insert(&p2,2);
    insert(&p2,3);
    insert(&p2,3);
    insert(&p2,4);
    insert(&p2,5);
    insert(&p2,6);

    printlist(p2);
    struct poly* result = addpoly(p1,p2);
    
    printlist(result);
    





}