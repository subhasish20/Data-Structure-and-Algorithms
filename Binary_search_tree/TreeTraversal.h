#ifndef TREE_TRAVERSAL
#define TREE_TRAVERSAL

#include <stdio.h>
#include "BSTNode.h"

/* Preorder Traversal: Root -> Left -> Right */
static void PreorderTraversal(BSTNode* root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    PreorderTraversal(root->LChild);
    PreorderTraversal(root->RChild);
}

/* Inorder Traversal: Left -> Root -> Right */
static void InOrderTraversal(BSTNode* root)
{
    if (root == NULL)
        return;

    InOrderTraversal(root->LChild);
    printf("%d ", root->data);
    InOrderTraversal(root->RChild);
}

/* Postorder Traversal: Left -> Right -> Root */
static void PostOrderTraversal(BSTNode* root)
{
    if (root == NULL)
        return;

    PostOrderTraversal(root->LChild);
    PostOrderTraversal(root->RChild);
    printf("%d ", root->data);
}

#endif
