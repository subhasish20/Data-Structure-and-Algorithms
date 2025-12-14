#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}AVLtreeNode;

AVLtreeNode* CreateNode(int value)
{
    AVLtreeNode* node = (AVLtreeNode*)malloc(sizeof(AVLtreeNode));

    node->data = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int main()
{
    AVLtreeNode* root = CreateNode(40);

    printf("%d",root->data);

    return 0;
}