#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left, * right;

};


struct node* createnode(int val){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp-> data = val;
    temp->left= NULL;
    temp->right = NULL;
    return temp;
} 

void inorder(struct node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
}

void levelOrder(struct node* root) {
    if (root == NULL) return;

    struct node** queue = (struct node**)malloc(sizeof(struct node*) * 1000);
    int front = 0, rear = 0;
    queue[rear++] = root;
    queue[rear++] = NULL; // Mark the end of the first level

    while (front < rear) {
        struct node* current = queue[front++];

        if (current == NULL) {
            printf("\n"); // Move to the next level
            if (front == rear) break; // If this was the last level, exit the loop
            queue[rear++] = NULL; // Mark the end of the next level
            continue;
        }

        printf("%d ", current->data);

        if (current->left) {
            queue[rear++] = current->left;
        }
        if (current->right) {
            queue[rear++] = current->right;
        }
    }
    free(queue);
}
// insert function to insert in a bst



void insert(struct node* root, int val) {
    struct node* prev = NULL;
    struct node* current = root;

    while (current != NULL) {
        prev = current;
        if (val == current->data) {
            return;
        } else if (val < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    struct node* temp = createnode(val);
    if (prev == NULL) {
        root = temp; 
    } else if (val < prev->data) {
        prev->left = temp;
    } else {
        prev->right = temp;
    }
}

int main() {
    struct node* root = createnode(5);
    struct node* p1 = createnode(3);
    struct node* p2 = createnode(6);
    struct node* p3 = createnode(1);
    struct node* p4 = createnode(4);
    root ->left  = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;

    // inorder(root);
    // printf("\n");
    // levelOrder(root);
    // printf("\n");
    insert(root,7);
    // inorder(root);
    printf("\n");
    levelOrder(root);
    insert(root,10);
    insert(root,9);
    insert(root,6);
    insert(root,8);
    
        insert(root,-3);
            insert(root,0);
levelOrder(root);




				
	return 0;
}