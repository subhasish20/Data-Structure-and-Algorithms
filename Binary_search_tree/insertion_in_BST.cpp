#include<iostream>
#include"BSTNode.h"
#include"TreeTraversal.h"
using namespace std;

BSTNode* CreateNode(int key)
{
    BSTNode* node = new BSTNode();

    node->LChild = NULL;
    node->data = key;
    node->RChild = NULL;

    return node;
} 

BSTNode* InsertInBST(BSTNode* root, int key)
{
    if (root == nullptr)
        return CreateNode(key);

    if (key < root->data)
        root->LChild = InsertInBST(root->LChild, key);
    else if (key > root->data)
        root->RChild = InsertInBST(root->RChild, key);

    return root;
}

int FreeAllNodes(BSTNode* root)
{
    if(root == NULL)
    return 0;

    FreeAllNodes(root->LChild);
    FreeAllNodes(root->RChild);

    delete root;

    return 0;
}

int main()
{
    int size;
    cout<<"Enter how many nodes you want to insert in the Binary Search Tree :";
    cin>>size;
    int i = 0, key;

    cout<<"Enter the root node :";
    cin>>key;
    BSTNode* root = CreateNode(key);
    
    for(i = 1; i < size; i++)
    {
        cout<<"Enter the "<< i+1 << " value :";
        cin>>key;
        root = InsertInBST(root,key);
    }

    PreorderTraversal(root);
    FreeAllNodes(root);

    return 0; 
}