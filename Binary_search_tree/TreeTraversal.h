#ifndef TREE_TRAVERSAL
#define TREE_TRAVERSAL

#include <stdio.h>
#include "BSTNode.h"

/* Preorder Traversal: Root -> Left -> Right */
static void PreorderTraversal(Node* root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    PreorderTraversal(root->lchild);
    PreorderTraversal(root->rchild);
}

/* Inorder Traversal: Left -> Root -> Right */
static void InOrderTraversal(Node* root)
{
    if (root == NULL)
        return;

    InOrderTraversal(root->lchild);
    printf("%d ", root->data);
    InOrderTraversal(root->rchild);
}

/* Postorder Traversal: Left -> Right -> Root */
static void PostOrderTraversal(Node* root)
{
    if (root == NULL)
        return;

    PostOrderTraversal(root->lchild);
    PostOrderTraversal(root->rchild);
    printf("%d ", root->data);
}

#endif
