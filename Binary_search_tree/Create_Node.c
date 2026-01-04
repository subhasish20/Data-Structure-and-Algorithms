#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    struct Node* LChild;
    int data;
    struct Node* RChild;
}Node;

Node* CreateNode(int key)
{
    Node* node = (Node*)malloc(sizeof(Node)); // it will create a node using DMA

    node->LChild = NULL; // make the left chile null
    node->data = key; // giving the value to the node
    node->RChild = NULL;

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