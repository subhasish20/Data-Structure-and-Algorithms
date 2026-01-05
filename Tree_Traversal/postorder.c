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

/* Postorder Traversal: Left -> Right -> Root */
void PostTraversal(TreeNode* root)
{
    if (root == NULL)
        return;

    PostTraversal(root->lchild);
    PostTraversal(root->rchild);       
    printf("%d ", root->data);                 
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
    PostTraversal(root);  // Perform in-order traversal
    printf("\n");

    return 0;
}
