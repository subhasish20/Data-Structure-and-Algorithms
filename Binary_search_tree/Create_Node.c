#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    struct Node* lchild;
    int data;
    struct Node* rchild;
}Node;

Node* CreateNode(int key)
{
    Node* node = (Node*)malloc(sizeof(Node)); // it will create a node using DMA

    node->lchild = NULL; // make the left chile null
    node->data = key; // giving the value to the node
    node->rchild = NULL;

    return node;
}

int main()
{
    Node* root = CreateNode(50);
    if(root != NULL)
    {
        printf("Node Created Successfully");
    }
    else 
    {
        printf("Node not created");
    }
    free(root);

    return 0;
}