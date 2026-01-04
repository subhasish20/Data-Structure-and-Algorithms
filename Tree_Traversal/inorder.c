#include <stdio.h>
#include <stdlib.h>
#include "TreeNode.h"  


TreeNode* CreateTreeNode(int key)
{
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = key;
    node->LChild = NULL;
    node->RChild = NULL;
    return node;
}

/* Inorder Traversal: Left -> Root -> Right */
void InOrderTraversal(TreeNode* root)
{
    if (root == NULL)
        return;

    InOrderTraversal(root->LChild);       
    printf("%d ", root->data);            
    InOrderTraversal(root->RChild);     
}

int main()
{
    // Creating the root node
    TreeNode* root = CreateTreeNode(50);

    // Adding children
    root->LChild = CreateTreeNode(20);
    root->RChild = CreateTreeNode(70);

    root->LChild->LChild = CreateTreeNode(10);
    root->LChild->RChild = CreateTreeNode(30);

    root->RChild->LChild = CreateTreeNode(60);
    root->RChild->RChild = CreateTreeNode(80);

    printf("In-order traversal of the tree: ");
    InOrderTraversal(root);  // Perform in-order traversal
    printf("\n");

    return 0;
}
