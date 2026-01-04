#ifndef FREE_ALL_NODES_H
#define FREE_ALL_NODES_H

#include <stdlib.h>
#include "BSTNode.h"

static void freeAllNodes(BSTNode* root)
{
    if (root == NULL)
        return;

    freeAllNodes(root->LChild);
    freeAllNodes(root->RChild);
    free(root);
}

#endif