#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int x) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->val = x;
    temp->left = temp->right = NULL;
    return temp;
}

// Check if tree is Complete Binary Tree (CBT)
int isCompleteBinaryTree(Node* root) {
    if (root == NULL) 
        return 1;

    // Simple queue (array-based)
    Node* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int nullSeen = 0;

    while (front < rear) {
        Node* node = queue[front++];

        if (node == NULL) {
            nullSeen = 1;
        } 
        else {
            if (nullSeen == 1)
                return 0;  // Found a non-NULL after NULL → Not CBT

            queue[rear++] = node->left;
            queue[rear++] = node->right;
        }
    }

    return 1;
}

void freeTree(Node* root) {
    if (root == NULL) return;
    
    // Recursively free the left and right subtrees first
    freeTree(root->left);
    freeTree(root->right);
    
    // Free the current node
    free(root);
}


int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);

    if (isCompleteBinaryTree(root))
        printf("Tree is a Complete Binary Tree\n");
    else
        printf("Tree is NOT a Complete Binary Tree\n");

    freeTree(root);
    return 0;
}
