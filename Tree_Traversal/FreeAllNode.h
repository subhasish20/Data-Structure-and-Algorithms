#ifndef FREE_ALL_NODES_H
#define FREE_ALL_NODES_H

#include <stdlib.h>
#include"TreeNode.h"

static void freeAllNodes(TreeNode* root)
{
    if (root == NULL)
        return;

    freeAllNodes(root->lchild);
    freeAllNodes(root->rchild);
    free(root);
}

#endif