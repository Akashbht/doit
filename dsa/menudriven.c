#include <stdio.h>
#include<stdlib.h>



struct nd{
    int data;
    struct nd* next;

};




struct nodedouble {
    int data;
    struct nodedouble* next;
    struct nodedouble* prev;
};





struct stackarray {
    int *arr;
    int capacity, size, top;
};





struct liststack {
    struct nd* head;
    int size;
}s1;




struct queue {
    int *arr;
    int capacity, front, rear,size;
};



void insertatbeginsinglylinked(struct nd** head, int val){
    struct nd* temp = (struct nd*)malloc(sizeof(struct nd));
    
    temp->data=val;
    temp->next=NULL;
    if (!head){
        
        *head = temp;
        return;
    }
    temp -> next=(*head);
    (*head) = temp;
    
    
};





void insertatendsinglylinked(struct nd** head, int val){
    struct nd* temp = (struct nd*)malloc(sizeof(struct nd));
    temp->data=val;
    temp->next=NULL;
    if (!head){
        *head = temp;
        return;
    }
    struct nd* itr =  *head;
    while(itr->next){
        itr = itr -> next;
    }
    itr->next = temp;

};





void insertaftersinglylinked(struct nd** head,int k, int val){
    struct nd* temp = (struct nd*)malloc(sizeof(struct nd));
    temp->data=val;
    temp->next=NULL;
    if (!head){
        *head = temp;
        return;
    }
    struct nd* itr =  *head;
    while(itr->data!=k && (itr->next)){
        itr = itr -> next;
    }
    temp->next = itr->next;
    itr->next = temp;

};





void printlistsinglylinked(struct nd** head){
    printf("\n\n");
    if(!head){
        printf("List is empty\n");
        return;
    }
    struct nd* itr = (*head);
    while(itr!= NULL ){
        

        printf("%d ",itr->data );
        printf("\t");
        itr = itr->next;
        
    }
    printf("\n\n");
};





void deletebeginsinglylinked(struct nd** head){
    if((*head)==NULL ||(*head)->next==NULL ){
        (*head) = NULL;
        return;
    }
    (*head) = (*head)-> next;
    return;
}

void deleteatksinglylinked(struct nd** head, int k){
    if((*head)==NULL ||(*head)->next==NULL ){
        (*head) = NULL;
        return;
    }
    struct nd* itr = (*head);
    while((itr -> next )-> data != k ){
        itr = itr -> next;
    }
    itr->next = itr ->next -> next;
    return;
}


void deleteendsinglylinked(struct nd** head){
    if((*head)==NULL ||(*head)->next==NULL ){
        (*head) = NULL;
        return;
    }
    struct nd* itr = (*head);
    while(((itr -> next )-> next ) !=NULL){
        itr = itr -> next;
    }
    itr->next = NULL;
    return;
}


void insertatbegindoublylinked(struct nodedouble** head, int val) {
    struct nodedouble* temp = (struct nodedouble*)malloc(sizeof(struct nodedouble));
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

void printlistdoublylinked(struct nodedouble** head){
    if(!(*head)){
        printf("List is empty\n");
        return;
    }
    struct nodedouble* itr = (*head);
    while(itr!= NULL ){
        

        printf("%d ",itr->data );
        printf("\t");
        itr = itr->next;
        
    }
};




void insertatenddoublylinked(struct nodedouble** head, int val) {
    struct nodedouble* temp = (struct nodedouble*)malloc(sizeof(struct nodedouble));
    temp->data = val;
    temp->next = NULL;
    if (!(*head)) {
        temp->prev = NULL; 
        *head = temp;
        return;
    }
    struct nodedouble* itr = *head;
    while (itr->next) {
        itr = itr->next;
    }
    itr->next = temp;
    temp->prev = itr;
}





void insertafterdoublylinked(struct nodedouble** head, int k, int val) {
    struct nodedouble* temp = (struct nodedouble*)malloc(sizeof(struct nodedouble));
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;
    if (!(*head)) {
        printf("List is empty\n");
        return;
    }
    struct nodedouble* itr = *head;
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





struct nodedouble* createdoublenode(int data) {
    struct nodedouble* temp = (struct nodedouble*)malloc(sizeof(struct nodedouble));
    if (temp == NULL) {
        printf("allocation failed\n");
        return NULL;
    }
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}






void deletebegindoublylinked(struct nodedouble** head) {
    if (!head || !(*head)) {
        printf("List is empty\n");
        return;
    }
    struct nodedouble* temp = *head;
    *head = (*head)->next;
    if (*head) {
        (*head)->prev = NULL;
    }
    free(temp);
}





void deleteenddoublylinked(struct nodedouble** head) {
    if (!head || !(*head)) {
        printf("List is empty\n");
        return;
    }
    struct nodedouble* itr = (*head);
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





void deleteatkdoublylinked(struct nodedouble** head, int k) {
    if (!head || !(*head)) {
        printf("List is empty\n");
        return;
    }
    struct nodedouble* itr = (*head);
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





void insertatbegincircularlylinked(struct nodedouble** head, int val) {
    struct nodedouble* temp = (struct nodedouble*)malloc(sizeof(struct nodedouble));
    temp->data = val;
    if (!(*head)) {
        temp->next = temp; 
        temp->prev = temp; 
    } else {
        temp->next = *head;
        temp->prev = (*head)->prev;
        (*head)->prev->next = temp;
        (*head)->prev = temp;
    }
    *head = temp;
}









void printlistcircularlylinked(struct nodedouble** head) {
    if (!(*head)) {
        printf("List is empty\n");
        return;
    }
    struct nodedouble* itr = (*head);
    do {
        printf("%d ", itr->data);
        printf("\t");
        itr = itr->next;
    } while (itr != (*head)); 
    printf("\n");
}







void insertatendcircularlylinked(struct nodedouble** head, int val) {
    struct nodedouble* temp = (struct nodedouble*)malloc(sizeof(struct nodedouble));
    temp->data = val;
    if (!(*head)) {
        temp->next = temp; 
        temp->prev = temp; 
        *head = temp;
        return;
    }
    struct nodedouble* last = (*head)->prev; 
    temp->next = *head;
    temp->prev = last;
    last->next = temp;
    (*head)->prev = temp;
}

void insertaftercircularlylinked(struct nodedouble** head, int k, int val) {
    struct nodedouble* temp = (struct nodedouble*)malloc(sizeof(struct nodedouble));
    temp->data = val;
    if (!(*head)) {
        printf("List is empty\n");
        return;
    }
    struct nodedouble* itr = *head;
    while (itr->data != k && itr->next != (*head)) {
        itr = itr->next;
    }
    temp->next = itr->next;
    temp->prev = itr;
    itr->next->prev = temp;
    itr->next = temp;
}






void deletebegincircularlylinked(struct nodedouble** head) {
    if (!(*head)) {
        printf("list is empty\n");
        return;
    }
    struct nodedouble* temp = *head;
    if (temp->next == temp) {
        *head = NULL;
    } else {
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        *head = temp->next;
    }
    free(temp);
}




void deleteendcircularlylinked(struct nodedouble** head) {
    if (!(*head)) {
        printf("list is empty\n");
        return;
    }
    struct nodedouble* temp = *head;
    if (temp->next == temp) {
        *head = NULL; 
    } else {
        temp = temp->prev;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    free(temp);
}





void deleteatkcircularlylinked(struct nodedouble** head, int k) {
    if (!(*head)) {
        printf("list is empty\n");
        return;
    }
    struct nodedouble* temp = *head;
    while (temp->data != k && temp->next != (*head)) {
        temp = temp->next;
    }
    if (temp->data != k) {
        printf("Element %d not found \n", k);
        return;
    }
    if (temp->next == temp) {
        *head = NULL; 
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        if (temp == *head) {
            *head = temp->next;
        }
    }
    free(temp);
}







void pusharr(struct stackarray *s1, int val) {
    if (s1->size == s1->capacity) {
        printf("Stack Overflow\n");
        return;
    }
    s1->top++;
    s1->arr[s1->top] = val;
    s1->size++;
}




int sizearr(struct stackarray* s1){
    if (s1->top == -1) {
        printf("empty stack\n");
        return -1;
    }
    return s1->size;
}





int poparr(struct stackarray *s1) {
    if (s1->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    int val = s1->arr[s1->top];
    s1->top--;
    s1->size--;
    return val;
}




void printstackarr(struct stackarray *s1) {
    if (s1->top == -1) {
        printf("Empty Stack\n");
        return;
    }
    for (int i = 0; i <= s1->top; i++) {
        printf("%d\t", s1->arr[i]);
    }
    printf("\n");
}





int toparr(struct stackarray *s1) {
    if (s1->top == -1) {
        printf("Empty Stack\n");
        return -1;
    }
    int top = s1->arr[s1->top];
    return top;
}




void initialisearr(struct stackarray *s1, int cap) {
    s1->capacity = cap;
    s1->size = 0;
    s1->top = -1;
    s1->arr = (int *)malloc(sizeof(int) * cap);
}


void initialiseliststack(struct liststack* s1) {
    s1->head= NULL;
    s1->size = 0;

    return ;

}
void pushliststack(struct liststack *s1, int val) {
    struct nd* temp = (struct nd*)malloc(sizeof(struct nd));
    temp ->data =val ;
    temp->next = s1->head;
    s1->head = temp;
    s1->size++;
}

int popliststack(struct liststack *s1) {
    if(s1->size == 0){
        printf("empty liststack. \n");
        return 0;
    }
    int val = s1->head->data;
    s1->head = s1->head->next;
    s1->size--;
    return val;

}

void printliststack(struct liststack *s1) {
    if (s1->size == 0){
        printf("empty liststack.\n ");
        return ;

    }
    struct nd* temp = s1->head;
    while(temp){
        printf("%d  \t", temp->data);
        temp= temp->next;
    }
    printf("\n");
}

int topliststack(struct liststack *s1) {
    if(s1->size == 0){
        printf("empty liststack. \n");
        return 0;
    }
    return s1->head->data;

}

int sizeliststack(struct liststack *s1){
    if(s1->size == 0){
        printf("empty liststack \n");
        return 0;
    }
    return   s1-> size;
}



struct queue* initialisequeue(int cap) {
    struct queue* temp = (struct queue*)malloc(sizeof(struct queue));
    temp->capacity=cap;

    temp->front = -1;
    temp->rear = -1;
    temp -> size = 0; 
    temp->arr = (int *)malloc(sizeof(int) * cap);
    return temp;
}

void enque(struct queue* q1, int value){
    if(q1->size == q1->capacity){
        printf("Queue is full\n");
        return ;
    }
    q1->arr[q1->rear] = value;
    q1->rear = (q1->rear + 1)% q1->capacity;
    
    q1->size++;

}

int deque(struct queue*q1){
    if(q1->size ==0){
        printf("empty queue");
        return 0;

    }
    int val = (q1->arr[q1->front]);
    q1-> front = (q1->front + 1)%q1->capacity;
    q1->size--;
    return val; 
}

void printqueue(struct queue* q1) {
    if (q1->size ==0) {
        printf("queue empty\n");
        return;
    }
    int i = q1->front;
    do {
        printf("%d ", q1->arr[i]);
        i = (i + 1) % q1->capacity; 
    } while (i != (q1->rear + 1) % q1->capacity);
    printf("\n");
}





int main(){





    struct nd* head = NULL;
    struct nodedouble* dhead = NULL;
    struct stackarray s1;
    struct liststack s2;
    int choice,val;



    printf("THIS IS A MENU DRIVEN PROGRAM :\n");
    printf("what you want to work with  \n");
    printf("Enter 1 for LINKED LISTS \n");
    printf("Enter 2 for STACKS\n");
    



    int a;
    scanf("%d",&a);


    switch(a){
        case(1):
             //            linked_lists();
            printf("Enter 1 for  SINGLY LINKED LISTS ::\n");

            printf("Enter 2 for  DOUBLY LINKED LISTS ::\n");
            printf("Enter 3 for  CIRCULAR LINKED LISTS ::\n");
            int b;
            scanf("%d",&b);

            switch (b){
                case 1:

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

                case 2:

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


                case 3:

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
                                insertatbegincircularlylinked(&dhead, val);
                                break;

                            case 2:
                                printf("Enter the value to insert: ");
                                scanf("%d", &val);
                                insertatendcircularlylinked(&dhead, val);
                                break;

                            case 3:
                                printf("Enter the value to insert after: ");
                                int k;
                                scanf("%d", &k);
                                printf("Enter the value to insert: ");
                                scanf("%d", &val);
                                insertaftercircularlylinked(&dhead, k, val);
                                break;

                            case 4:
                                deletebegincircularlylinked(&dhead);
                                break;

                            case 5:
                                deleteendcircularlylinked(&dhead);
                                break;

                            case 6:
                                printf("Enter the value to delete: ");
                                scanf("%d", &k);
                                deleteatkcircularlylinked(&dhead, k);
                                break;

                            case 7:
                                printlistcircularlylinked(&dhead);
                                break;

                            case 8:
                                return 0;

                            default:
                                printf("Invalid choice. Please try again.\n");
                        }
                    }

            }

        
        
        case 2:


            // stack
            printf("Enter 1 for ARRAY STACK : \n");
            printf("Enter 2 for LINKED LIST STACK : \n");
            int x;
            scanf("%d",&x);
            
            switch (x)
            {
                
                case 1:
                     printf("Enter the capacity of stackarray : \n");
                    int cap;
                    scanf("%d",&cap);
                    initialisearr(&s1,cap);
                    while (1) {
                        
                        printf("Enter 1 for PUSH : \n");
                        printf("Enter 2 for POP : \n");
                        printf("Enter 3 for TOP : \n");
                        printf("Enter 4 to PRINT STACK : \n");
                        printf("Enter 5 to SIZE : \n");
                        printf("Enter 6 to Exit : \n");
                        scanf("%d",&choice);
                        switch (choice)
                        {
                        case 1:
                            printf("Enter the value to push :");
                            scanf("%d",&val);
                            pusharr(&s1,val);
                            break; 
                        case 2:
                        
                            printf("\n");    
                            int poppedvalue = poparr(&s1);
                            printf("popped value : %d \n",poppedvalue);
                            break; 
                            
                        
                        case 3:
                            printf("\n");
                            int top = toparr(&s1);
                            printf("TOP of the stack is : %d \n", top);
                            break; 
                        case 4:
                            printstackarr(&s1);
                            break; 
                        case 5:
                            printf("\n");
                            int size = sizearr(&s1);
                            printf("\n");
                            printf("Size of stack is %d \n\n",size);
                            break;
                        case 6:
                            return 0;
                        default:
                            printf("\n\n invalid choice , try again : \n\n");
                        
                        
                        
                        
                    
                        }
                    }

                case 2:
                    
                    initialiseliststack(&s2);
                    while (1) {
                        
                        printf("Enter 1 for PUSH : \n");
                        printf("Enter 2 for POP : \n");
                        printf("Enter 3 for TOP : \n");
                        printf("Enter 4 to PRINT STACK : \n");
                        printf("Enter 5 to SIZE : \n");
                        printf("Enter 6 to Exit : \n");
                        scanf("%d",&choice);
                        switch (choice)
                        {
                        case 1:
                            printf("Enter the value to push :");
                            scanf("%d",&val);
                            pushliststack(&s2,val);
                            break; 
                        case 2:
                        
                            printf("\n");    
                            int poppedvalue = popliststack(&s2);
                            printf("popped value : %d \n",poppedvalue);
                            break; 
                            
                        
                        case 3:
                            printf("\n");
                            int top = topliststack(&s2);
                            printf("TOP of the stack is : %d \n", top);
                            break; 
                        case 4:
                            printliststack(&s2);
                            break; 
                        case 5:
                            printf("\n");
                            int size = sizeliststack(&s2);
                            printf("\n");
                            printf("Size of stack is %d \n\n",size);
                            break;
                        case 6:
                            return 0;
                        default:
                            printf("\n\n invalid choice , try again : \n\n");
                        
                        
                        
                        
                    
                        }
                    }

            

            }  



        
                
    }   
}            









