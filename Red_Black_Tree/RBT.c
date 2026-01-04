#include <stdio.h>
#include <stdlib.h>

// Color definitions
#define RED 1
#define BLACK 0

// Node structure for Red-Black Tree
typedef struct Node {
    int data;
    int color; // RED or BLACK
    struct Node *left, *right, *parent;
} Node;

// Tree type definition
typedef struct {
    Node* root;
} RBTree;

// Create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->color = RED; // New nodes are always RED
    newNode->left = newNode->right = newNode->parent = NULL;
    return newNode;
}

// Function to perform left rotation
void leftRotate(Node** root, Node* x) {
    Node* y = x->right;
    x->right = y->left;
    
    if (y->left != NULL)
        y->left->parent = x;
    
    y->parent = x->parent;
    
    if (x->parent == NULL)
        *root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    
    y->left = x;
    x->parent = y;
}

// Function to perform right rotation
void rightRotate(Node** root, Node* y) {
    Node* x = y->left;
    y->left = x->right;
    
    if (x->right != NULL)
        x->right->parent = y;
    
    x->parent = y->parent;
    
    if (y->parent == NULL)
        *root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;
    
    x->right = y;
    y->parent = x;
}

// Fix violations after insertion
void fixInsert(Node** root, Node* k) {
    Node* parent = NULL;
    Node* grandparent = NULL;
    
    while ((k != *root) && (k->color == RED) && (k->parent->color == RED)) {
        parent = k->parent;
        grandparent = parent->parent;
        
        // Case A: Parent is left child of grandparent
        if (parent == grandparent->left) {
            Node* uncle = grandparent->right;
            
            // Case 1: Uncle is RED (Recoloring only)
            if (uncle != NULL && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                k = grandparent;
            } else {
                // Case 2: k is right child (Left rotation)
                if (k == parent->right) {
                    leftRotate(root, parent);
                    k = parent;
                    parent = k->parent;
                }
                
                // Case 3: k is left child (Right rotation and recolor)
                rightRotate(root, grandparent);
                int temp = parent->color;
                parent->color = grandparent->color;
                grandparent->color = temp;
                k = parent;
            }
        }
        // Case B: Parent is right child of grandparent
        else {
            Node* uncle = grandparent->left;
            
            // Case 1: Uncle is RED (Recoloring only)
            if (uncle != NULL && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                k = grandparent;
            } else {
                // Case 2: k is left child (Right rotation)
                if (k == parent->left) {
                    rightRotate(root, parent);
                    k = parent;
                    parent = k->parent;
                }
                
                // Case 3: k is right child (Left rotation and recolor)
                leftRotate(root, grandparent);
                int temp = parent->color;
                parent->color = grandparent->color;
                grandparent->color = temp;
                k = parent;
            }
        }
    }
    
    (*root)->color = BLACK; // Root is always BLACK
}

// Insert a new node into the tree
void insert(Node** root, int data) {
    // Create new node
    Node* newNode = createNode(data);
    
    // If tree is empty
    if (*root == NULL) {
        newNode->color = BLACK; // Root is BLACK
        *root = newNode;
        return;
    }
    
    // Standard BST insertion
    Node* current = *root;
    Node* parent = NULL;
    
    while (current != NULL) {
        parent = current;
        if (data < current->data)
            current = current->left;
        else if (data > current->data)
            current = current->right;
        else {
            printf("Duplicate value %d not allowed\n", data);
            free(newNode);
            return;
        }
    }
    
    newNode->parent = parent;
    
    if (data < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
    
    // Fix Red-Black Tree violations
    fixInsert(root, newNode);
}

// Inorder traversal
void inorder(Node* root) {
    if (root == NULL)
        return;
    
    inorder(root->left);
    printf("%d(%s) ", root->data, root->color == BLACK ? "B" : "R");
    inorder(root->right);
}

// Preorder traversal
void preorder(Node* root) {
    if (root == NULL)
        return;
    
    printf("%d(%s) ", root->data, root->color == BLACK ? "B" : "R");
    preorder(root->left);
    preorder(root->right);
}

// Get color name for printing
const char* getColorName(int color) {
    return color == BLACK ? "Black" : "Red";
}

// Search for a node
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data)
        return root;
    
    if (data < root->data)
        return search(root->left, data);
    
    return search(root->right, data);
}

// Count black nodes in a path (for verification)
int countBlackNodes(Node* node) {
    int count = 0;
    while (node != NULL) {
        if (node->color == BLACK)
            count++;
        node = node->left;
    }
    return count;
}

// Initialize a Red-Black Tree
RBTree* createRBTree() {
    RBTree* tree = (RBTree*)malloc(sizeof(RBTree));
    tree->root = NULL;
    return tree;
}

// Main function
int main() {
    // Create a new Red-Black Tree
    RBTree* tree = createRBTree();
    
    printf("Red-Black Tree Implementation\n");
    printf("=============================\n");
    printf("RED = %d, BLACK = %d\n\n", RED, BLACK);
    
    // Insert nodes
    int values[] = {7, 3, 18, 10, 22, 8, 11, 26, 2, 6, 13};
    int n = sizeof(values)/sizeof(values[0]);
    
    printf("Inserting %d values: ", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", values[i]);
        insert(&tree->root, values[i]);
    }
    printf("\n");
    
    printf("\nTree Traversals:\n");
    printf("Inorder traversal:   ");
    inorder(tree->root);
    printf("\n");
    
    printf("Preorder traversal:  ");
    preorder(tree->root);
    printf("\n");
    
    // Search for nodes
    printf("\nSearch Operations:\n");
    int searchValues[] = {10, 18, 5, 13};
    for (int i = 0; i < 4; i++) {
        Node* found = search(tree->root, searchValues[i]);
        if (found)
            printf("Found %d: Color = %s\n", 
                   searchValues[i], getColorName(found->color));
        else
            printf("%d not found\n", searchValues[i]);
    }
    
    // Verify tree property
    if (tree->root != NULL) {
        printf("\nTree Properties:\n");
        printf("Root is %s (must be black)\n", 
               getColorName(tree->root->color));
        
        int blackNodesCount = countBlackNodes(tree->root);
        printf("Black nodes in leftmost path: %d (all paths should have same)\n", 
               blackNodesCount);
    }
    
    free(tree);
    return 0;
}