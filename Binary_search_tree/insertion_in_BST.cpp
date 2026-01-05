#include<iostream>
#include"BSTNode.h"
#include"TreeTraversal.h"
using namespace std;

Node* CreateNode(int key)
{
    Node* node = new Node();

    node->lchild = NULL;
    node->data = key;
    node->rchild = NULL;

    return node;
} 

Node* InsertInBST(Node* root, int key)
{
    if (root == nullptr)
        return CreateNode(key);

    if (key < root->data)
        root->lchild = InsertInBST(root->lchild, key);
    else if (key > root->data)
        root->rchild = InsertInBST(root->rchild, key);

    return root;    
}

int FreeAllNodes(Node* root)
{
    if(root == NULL)
    return 0;

    FreeAllNodes(root->lchild);
    FreeAllNodes(root->rchild);

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
    Node* root = CreateNode(key);
    
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