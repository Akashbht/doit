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


// insert function to insert in a bst



struct node* insert(struct node* root, int val) {
    if (root == NULL){
        root = createnode(val);
        return root;
    }

    if(root->data > val){
        root -> left = insert(root->left , val);
    }
    else if(root->data <= val){
        root -> right = insert(root->right , val);
        }
    return root;
}

int search(struct node* root, int val){
    if(!root){
        return 0;
    }
    if(root -> data == val){
        return 1;
    }
    else if(val < root-> data){
        return search(root-> left,val);
    }
    else{
        return search(root->right,val);
    }
}

int minvaluenode(struct node* root){
    // if(root == NULL) return 0;
    while(root->left){
        root = root->left;
    }
    return root->data;
}

struct node* delete(struct node* root, int val){
    if(root == NULL)return NULL;
    if(root -> data == val){
        if(!root->left && !root->right) {
            free(root);
            return NULL;}
        if(!root->left && root->right){
            struct node* temp = root -> right;
            free(root);
            return temp;
        }
        if(root->left && !root->right){
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        if(root-> left && root->right){
            int mini = minvaluenode(root->right);
            root -> data = mini;
            root -> right = delete(root->right,mini);
            return root;
        }
    }
    if(root->data < val) root->right = delete(root->right, val);
    else root->left = delete(root->left, val);

    return root;
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
    root = insert(root,7);
    root = insert(root,10);
    root = insert(root,8);
    root = insert(root,9);
    root = insert(root,11);

    inorder(root);
    printf("\n");

    root = delete(root,8);
    inorder(root);
	return 0;
}