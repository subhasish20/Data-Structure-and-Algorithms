#include<stdio.h>
#include<stdlib.h>
#include"BSTNode.h"
#include"TreeTraversal.h"
#include"FreeAllNode.h"

Node* CreateNode(int key)
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->lchild = NULL;
    newNode->data = key;
    newNode->rchild = NULL;

    return newNode;
}

Node* FindInorderPredecessor(Node* root)
{
    if (root == NULL) return NULL;

    Node* temp = root;
    while (temp->rchild != NULL) {
        temp = temp->rchild;
    }
    return temp;
}



Node* DeleteANode(Node* root, int key)
{
    if(root == NULL)
    {
        return root;
    }
    else if (key < root->data) // if the given key is less than current node 
    {
        root->lchild = DeleteANode(root->lchild, key); // recursive call for reaching the key
    }
    else if ( key > root->data) // if the given key is greater than the current node
    {
        root->rchild = DeleteANode(root->rchild, key);
    }
    else if (key == root->data)
    {
        // if the given key is the leaf node ( there is no child node of the given key to delete)
        if(root->lchild == NULL && root->rchild == NULL)
        {
        free(root);
        root = NULL; // making the node null
        }
        // if the given key has a righ child
        else if (root->lchild == NULL)
        {
            Node* temp = root;
            root = root->rchild;
            free(temp);
        } 
        // if the given key has a left child
        else if (root->rchild == NULL)
        {
            Node* temp = root;
            root = root->lchild;
            free(temp);
        }
        /* if there is left and right subtree of the given key.
        it will fill by inorder predecessor or in order sucessor*/
        else
        {
            Node* temp = FindInorderPredecessor(root->lchild); // geting the inorder predeccor

            // copy the inorder predecessor
            root->data = temp->data;

            // Delete the inorder predecessor
            root->lchild = DeleteANode(root->lchild, temp->data);

        }
    }
    else
    {
        printf("Key now found in the Tree");
    }

    return root;
}


int main() {
    Node* root = CreateNode(50);
    root->lchild = CreateNode(30);
    root->rchild = CreateNode(70);
    root->lchild->lchild = CreateNode(20);
    root->lchild->rchild = CreateNode(40);
    root->rchild->lchild = CreateNode(60);
    root->rchild->rchild = CreateNode(80);

    printf("Inorder traversal before deletion: ");
    InOrderTraversal(root);
    printf("\n");

    root = DeleteANode(root, 20);  // Deleting leaf node
    printf("InOrder traversal after deletion of 20: ");
    InOrderTraversal(root);
    printf("\n");

    root = DeleteANode(root, 30);  // Deleting node with one child
    printf("InOrder traversal after deletion of 30: ");
    InOrderTraversal(root);
    printf("\n");

    root = DeleteANode(root, 50);  // Deleting node with two children
    printf("InOrder traversal after deletion of 50: ");
    InOrderTraversal(root);
    printf("\n");

    return 0;
}
