#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}treeNode;

treeNode* createNodeNode(int value)
{
    treeNode* node  = (treeNode*)malloc(sizeof(treeNode));
    node->data = value;
    node->left = NULL;
    node->right = NULL;


    return node;
}

int preorder(treeNode* root)
{
    if(root == NULL)
    {
        return 0;
    }
    // recursion for preorder
    printf("%d\t",root->data); // it will display root
    preorder(root->left); // left
    preorder(root->right); // right

    return 1;
}

void freeTree(treeNode* root) {
    if (root == NULL) return;
    
    // Recursively free the left and right subtrees first
    freeTree(root->left);
    freeTree(root->right);
    
    // Free the current node
    free(root);
}


int main()
{
    treeNode* root = createNodeNode(10);

    root->left = createNodeNode(20);
    root->left->left = createNodeNode(40);

    root->right = createNodeNode(30);
    (*root).right->right = createNodeNode(60); // or simple root->right->right also work
    root->right->left = createNodeNode(50);

    printf("The preorder traversal is :\n");
    preorder(root);

    freeTree(root);
    return 0;
}
