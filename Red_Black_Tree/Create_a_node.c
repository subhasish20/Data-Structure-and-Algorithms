#include<stdio.h>
#include<stdlib.h>

#define RED 1 // for red color
#define BLACK 0 // for black color
typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}RBTNode;


RBTNode* createNode(int value)
{
    RBTNode* node = (RBTNode*)malloc(sizeof(RBTNode));
    node->data = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

