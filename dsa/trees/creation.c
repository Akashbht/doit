#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node *left, *right;

};

struct llnode {
    struct node* data;
    struct llnode* next;
};


struct queue {
    struct llnode* front;
    struct llnode* rear;
    int size;
};

struct queue* initialiseQueue() {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

void enque(struct queue* q, struct node* root) {
    struct llnode* newNode = (struct llnode*)malloc(sizeof(struct llnode));
    newNode->data = root;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    q->size++;
}

void deque(struct queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return ;
    }

    // struct node* troot = q->front->data;
    struct llnode* temp = q->front;

    // if (q->front == q->rear) {
    //     q->front = NULL;
    //     q->rear = NULL;
    // } else {
    //     q->front = q->front->next;
    // }
    if(q->front ==NULL){
        q-> rear = NULL;
    }

    free(temp);
    q->size--;
    return ;
}
int isempty(struct queue* q){
    if(q->size == 0){
        return 1;

    }
    else{
        return 0;
    }
}

struct node* front(struct queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return NULL;
    }

    return q->front->data;
}

int size(struct queue* q) {
    return q->size;
}


struct node* new(int val){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp -> left = temp -> right = NULL;
    return temp;

}


// void intialisetree(struct node** root){
//     printf("enter data :");
//     int val;
//     scanf("%d",&val);
    

//     if(val == -1){
//         *root = NULL;
//         return;
//     }
//     *root = new(val);
//     printf("enter data to be inserted at left of %d \t", val);
//     intialisetree(&((*root)->left));
//     printf("enter data to be inserted at right of %d \t",val);
//     intialisetree(&((*root)->right));


// } 
struct node* initialisetree(int data) {
    if (data == -1) {
        return NULL; // Return NULL to represent an empty subtree
    }

    struct node* root = new(data); // Create a new node with the given data

    // Recursively initialize the left and right subtrees
    printf("Enter data for the left subtree of %d (-1 for empty): ", data);
    int leftData;
    scanf("%d", &leftData);
    root->left = initialisetree(leftData);

    printf("Enter data for the right subtree of %d (-1 for empty): ", data);
    int rightData;
    scanf("%d", &rightData);
    root->right = initialisetree(rightData);

    return root;
}

struct node* search(struct node* root, int val){
    if(root == NULL || root -> data == val ){
        return root;

    }
    else if(root -> data > val ){
        return search(root -> left, val);
    }
    else{
        return search(root-> right, val);
    }
}

void levelorder(struct node* root){

    if(!root)return ;
     
    printf("%d ",root->data);

    struct queue* q = initialiseQueue();
    enque(q,root);

    while(!isempty(q)){
        struct node* temp = q-> front->data;
        deque(q);
        printf("%d ", temp-> data);
        

        if(temp->left){
            enque(q,temp->left);
        }
        if(temp->right){
            enque(q, temp-> right);
        }
    }
    
}

void inorder(struct node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
}


int main(){

    struct node* root = initialisetree(1);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // root = (struct node*)malloc(sizeof(struct node));
    // root -> data = 5;
    // root -> left = (struct node*)malloc(sizeof(struct node));
    // root -> right = (struct node*)malloc(sizeof(struct node));
    // root -> left -> left = (struct node*)malloc(sizeof(struct node));
    // root -> left -> right = (struct node*)malloc(sizeof(struct node));
    // root -> left->left->left = (struct node*)malloc(sizeof(struct node));
    // root -> left->left->right = (struct node*)malloc(sizeof(struct node));
    // root -> right -> right  = (struct node*)malloc(sizeof(struct node));
    // root -> right ->left = (struct node*)malloc(sizeof(struct node));

    // root -> left -> data =  3;
    // root -> right -> data =  6;
    // root -> left -> left -> data = 1 ;
    // root -> left -> right -> data = 4 ;
    // root -> left->left->left -> data = 0 ;
    // root -> left->left->right -> data = 2 ;
    // root -> right -> right  -> data = 7 ;
    // root -> right ->left -> data =  3;


    // printf("\n %d \n", root -> data);
    // printf(" %d ",root -> left -> data);
    // printf(" %d \n",root -> right -> data);
    
    // printf(" %d ",root -> left -> left -> data);
    // printf(" %d ",root -> left -> right -> data);
    // printf(" %d ",root -> right -> left  -> data);
    // printf(" %d \n",root -> right ->right -> data);

    // printf(" %d ",root -> left->left->left -> data);
    // printf(" %d \n", root -> left->left->right -> data );
    
    
    
    levelorder(root);

    // struct node* searched = search(root, 6);
    // struct node* m = search(root, 6);
    // if( m!= NULL){
    //     printf("found %d", m-> data);
    // }
    // else{
    //     printf("not found");
    // }
    // struct node* n = search(root, 9);
    // if( n!= NULL){
    //     printf("found %d", n-> data);
    // }
    // else{
    //     printf("not found");
    // }

    return 0;
}