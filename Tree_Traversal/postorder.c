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

/* Postorder Traversal: Left -> Right -> Root */
void PostTraversal(TreeNode* root)
{
    if (root == NULL)
        return;

    PostTraversal(root->LChild);
    PostTraversal(root->RChild);       
    printf("%d ", root->data);                 
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
    PostTraversal(root);  // Perform in-order traversal
    printf("\n");

    return 0;
}
