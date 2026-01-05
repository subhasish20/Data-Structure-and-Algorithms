#include <stdio.h>
#include <stdlib.h>
#include "TreeNode.h"  


TreeNode* CreateTreeNode(int key)
{
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = key;
    node->lchild = NULL;
    node->rchild = NULL;
    return node;
}

/* Inorder Traversal: Left -> Root -> Right */
void InOrderTraversal(TreeNode* root)
{
    if (root == NULL)
        return;

    InOrderTraversal(root->lchild);       
    printf("%d ", root->data);            
    InOrderTraversal(root->rchild);     
}

int main()
{
    // Creating the root node
    TreeNode* root = CreateTreeNode(50);

    // Adding children
    root->lchild = CreateTreeNode(20);
    root->rchild = CreateTreeNode(70);

    root->lchild->lchild = CreateTreeNode(10);
    root->lchild->rchild = CreateTreeNode(30);

    root->rchild->lchild = CreateTreeNode(60);
    root->rchild->rchild = CreateTreeNode(80);

    printf("In-order traversal of the tree: ");
    InOrderTraversal(root);  // Perform in-order traversal
    printf("\n");

    return 0;
}
