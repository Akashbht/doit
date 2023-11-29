#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createnode(int key) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = key;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct node* insert(struct node* root, int key) {
    if (root == NULL) {
        return createnode(key);
    }

    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    }

    return root;
}


struct node* search(struct node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);
    } else {
        
        return search(root->right, key);
    }
}

struct node* minValueNode(struct node* node) {
    struct node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct node* deletenode(struct node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deletenode(root->left, key);
    } else if (key > root->data) {
        root->right = deletenode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deletenode(root->right, temp->data);
    }
    return root;
}

int countleafnodes(struct node* root) {
    if (root == NULL) {
        return 0;
    }

    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    return countleafnodes(root->left) + countleafnodes(root->right);
}

int treeheight(struct node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftheight = treeheight(root->left);
    int rightheight = treeheight(root->right);

    return (leftheight > rightheight) ? (leftheight + 1) : (rightheight + 1);
}

int countnodesfromright(struct node* root) {
    if (root == NULL) {
        return 0;
    }

    return 1 + countnodesfromright(root->right) + countnodesfromright(root->left);
}

int kthlargestelement(struct node* root, int k) {
// Base case: If the tree is empty or we've found 'k' nodes in the left subtree and not yet reached our target
if (k < 0 || k >= countnodesfromright(root)) {
    return -1;
    }
    // If the element is in the left subtree of the current node
    else if (countnodesfromright(root->left) < k) {
        return kthlargestelement(root->right, k - countnodesfromright(root->left));
        }
        // Else the element is in the right subtree of the current node
        else {
            return kthlargestelement(root->left, k);
            }            
}

void displaytree(struct node* root, int level) {
    if (root != NULL) {
        displaytree(root->right, level + 1);
        for (int i = 0; i < level; i++) {
            printf("   "); 
        }
        printf("%d\n", root->data);
        displaytree(root->left, level + 1);
    }
}

int main() {
    struct node* root = NULL;
    int n, value;

    printf("Enter the number of elements in the binary search tree: ");
    scanf("%d", &n);

    printf("Enter the elements of the binary search tree:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Enter the key to search: ");
    scanf("%d", &value);
    if (search(root, value) != NULL) {
        printf("Key %d found in the tree.\n", value);
    } else {
        printf("Key %d not found in the tree.\n", value);
    }

    printf("Enter the key to delete: ");
    scanf("%d", &value);
    root = deletenode(root, value);
    printf("Binary search tree after deleting key %d:\n", value);
    displaytree(root,0);

    int leafnodes = countleafnodes(root);
    printf("Total number of leaf nodes in the binary search tree: %d\n", leafnodes);

    int h = treeheight(root);
    printf("Height of the binary search tree: %d\n", h);

    int nodesfromright = countnodesfromright(root);
    printf("Total number of nodes from the right of the root: %d\n", nodesfromright);

    int k;
    printf("Enter the value of k for kth largest element: ");
    scanf("%d", &k);
    int kthlargest = kthlargestelement(root, k);
    if (kthlargest != -1) {
        printf("%dth largest element in the binary search tree: %d\n", k, kthlargest);
    } else {
        printf("Invalid value of k or not enough nodes in the tree.\n");
    }

    return 0;
}
