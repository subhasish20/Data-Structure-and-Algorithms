#ifndef TREE_NODE_CREATION
#define TREE_NODE_CREATION

typedef struct node {
    struct node* lchild;
    int data;
    struct node* rchild;
} TreeNode;

#endif