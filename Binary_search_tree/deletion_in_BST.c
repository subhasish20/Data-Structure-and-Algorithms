#include<stdio.h>
#include<stdlib.h>
#include"BSTNode.h"
#include"TreeTraversal.h"
#include"FreeAllNode.h"

BSTNode* CreateNode(int key)
{
    BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));

    newNode->LChild = NULL;
    newNode->data = key;
    newNode->RChild = NULL;

    return newNode;
}

BSTNode* FindInorderPredecessor(BSTNode* root)
{
    if (root == NULL) return NULL;

    BSTNode* temp = root;
    while (temp->RChild != NULL) {
        temp = temp->RChild;
    }
    return temp;
}



BSTNode* DeleteANode(BSTNode* root, int key)
{
    if(root == NULL)
    {
        return root;
    }
    else if (key < root->data) // if the given key is less than current node 
    {
        root->LChild = DeleteANode(root->LChild, key); // recursive call for reaching the key
    }
    else if ( key > root->data) // if the given key is greater than the current node
    {
        root->RChild = DeleteANode(root->RChild, key);
    }
    else if (key == root->data)
    {
        // if the given key is the leaf node ( there is no child node of the given key to delete)
        if(root->LChild == NULL && root->RChild == NULL)
        {
        free(root);
        root = NULL; // making the node null
        }
        // if the given key has a righ child
        else if (root->LChild == NULL)
        {
            BSTNode* temp = root;
            root = root->RChild;
            free(temp);
        } 
        // if the given key has a left child
        else if (root->RChild == NULL)
        {
            BSTNode* temp = root;
            root = root->LChild;
            free(temp);
        }
        /* if there is left and right subtree of the given key.
        it will fill by inorder predecessor or in order sucessor*/
        else
        {
            BSTNode* temp = FindInorderPredecessor(root->LChild); // geting the inorder predeccor

            // copy the inorder predecessor
            root->data = temp->data;

            // Delete the inorder predecessor
            root->LChild = DeleteANode(root->LChild, temp->data);

        }
    }
    else
    {
        printf("Key now found in the Tree");
    }

    return root;
}


int main() {
    BSTNode* root = CreateNode(50);
    root->LChild = CreateNode(30);
    root->RChild = CreateNode(70);
    root->LChild->LChild = CreateNode(20);
    root->LChild->RChild = CreateNode(40);
    root->RChild->LChild = CreateNode(60);
    root->RChild->RChild = CreateNode(80);

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
