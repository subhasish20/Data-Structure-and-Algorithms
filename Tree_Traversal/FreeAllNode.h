#ifndef FREE_ALL_NODES_H
#define FREE_ALL_NODES_H

#include <stdlib.h>
#include"TreeNode.h"

static void freeAllNodes(TreeNode* root)
{
    if (root == NULL)
        return;

    freeAllNodes(root->LChild);
    freeAllNodes(root->RChild);
    free(root);
}

#endif