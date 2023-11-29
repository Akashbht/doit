#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    int exp;
    struct node* next;
};

struct node* newnode(int data,int exp){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = data;
    temp -> exp  = exp;
    temp-> next = NULL;
    return temp;

}

void insert(struct node** head, int data,int exp){
    struct node* temp = newnode(data,exp);
    if(!(*head)){
        (*head) = temp;
        return ;
    }
    struct node* itr = (*head);
    while(itr->next !=NULL){
        itr=itr->next;
        }
    itr->next = temp;
    return;
    
}
void insertelements(struct node** head){
    int high;
    printf("enter the highest power of x in poly: \n");
    scanf("%d",&high);
    struct node* itr = (*head); 
    for(int i=0 ;i<=high;i++){
        int coeff ,exp;
        printf("\n enter coefficient of x%d: ",high-i);
        scanf("%d" , &coeff );
        insert(head,coeff,high-i);
    }
}


void printlist(struct node* head){
    if(!head){
        printf("List is empty\n");
        return;
    }
    struct node* itr = head;
    while(itr!= NULL ){
    
        printf("%d_x^%d \t",itr->data,itr->exp );
        itr = itr->next;
        
    }
    printf("\n");
};


struct node* addpoly(struct node* p1, struct node* p2){
    struct node* res = NULL, *itr;
    int c1 = p1->exp, c2 = p2->exp;
    
    if(c1<c2){
        struct node* temp = p1;
        p1 = p2;
        p2 = temp;
        int tempc = c1;
        c1 =  c2;
        c2  = tempc;
    }

    int difflength = c1 - c2, i =0 ;
    
    while(i<difflength){
        if(res == NULL){
            res = newnode(p1->data,p1->exp);
            itr = res;
            p1 = p1-> next;
        }
        else{
            itr -> next = newnode(p1->data,p1->exp);
            itr = itr->next;
            p1 = p1 -> next;
        }
        i++;
    }
    while(p1){
        if(!res){
            res = newnode(p1->data + p2->data,p1->exp);
            itr = res;
        }
        else {
            itr -> next = newnode(p1->data + p2->data,p1->exp);
            itr = itr -> next;

        }
        p1 = p1->next;
        p2 = p2-> next;
    }
    return res;


}


int main() {

    struct node* p1 , *p2 = NULL;

    insertelements(&p1);
    insertelements(&p2);
    printlist(p1);
    printlist(p2);
    struct node* result = addpoly(p1,p2);
    printlist(result);
    





    // insert(&p2,3);
    // insert(&p2,4);
    // insert(&p2,5);
    // insert(&p2,6);

    // printlist(p2);
    // struct node* result = add(p1,p2);
    
    // printlist(result);
    
}