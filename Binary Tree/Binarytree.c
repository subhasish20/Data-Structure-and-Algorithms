#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}treeNode;

treeNode* createNode(int value)
{
    treeNode* node = (treeNode*)malloc(sizeof(treeNode));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    
    return node;
}
int main()
{
    treeNode* root = createNode(5);
    /*
    treeNode* leftChildOfRoot = createNode(6);
    treeNode* righChildofRoot = createNode(7);

    root->left = leftChildOfRoot;
    root->right = righChildofRoot;
    */

    root->left = createNode(6);
    root->left->left = createNode(10);
    root->left->right = createNode(20);

    root->right = createNode(7);
    root->right->right = createNode(30);
    root->right->left = createNode(40);
    printf("          %d\n", root->data);                 
    printf("      /       \\\n");
    printf("     %d         %d\n", root->left->data, root->right->data); 
    printf("   /   \\     /   \\\n");
    printf("  %d    %d   %d    %d\n", 
           root->left->left->data, root->left->right->data,
           root->right->left->data, root->right->right->data);


    return 0;
}