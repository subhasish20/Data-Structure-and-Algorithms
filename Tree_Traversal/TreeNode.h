#ifndef TREE_NODE_CREATION
#define TREE_NODE_CREATION

typedef struct node {
    struct node* LChild;
    int data;
    struct node* RChild;
} TreeNode;

#endif