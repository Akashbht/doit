#include <stdio.h>
#include<stdlib.h>


struct liststack {
    struct singlenode* head;
    int size;
}s1;

struct singlenode{
    int data;
    struct singlenode* next;

};



void initialiseliststack(struct liststack* s1) {
    s1->head= NULL;
    s1->size = 0;

    return ;

}
void pushliststack(struct liststack *s1, int val) {
    struct singlenode* temp = (struct singlenode*)malloc(sizeof(struct singlenode));
    temp ->data =val ;
    temp->next = s1->head;
    s1->head = temp;
    s1->size++;
}

int popliststack(struct liststack *s1) {
    if(s1->size == 0){
        printf("empty liststack \n");
        return 0;
    }
    int val = s1->head->data;
    s1->head = s1->head->next;
    s1->size--;
    return val;

}

void printliststack(struct liststack *s1) {
    if (s1->size == 0){
        printf("empty liststack\n ");
        return ;

    }
    struct singlenode* temp = s1->head;
    while(temp){
        printf("%d  \t", temp->data);
        temp= temp->next;
    }
    printf("\n");
}

int topliststack(struct liststack *s1) {
    if(s1->size == 0){
        printf("empty liststack \n");
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


int main(){

    
    struct liststack s2;
    int choice,val;
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
