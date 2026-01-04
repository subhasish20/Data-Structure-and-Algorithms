#ifndef BSTNODE_H
#define BSTNODE_H

typedef struct node {
    struct node* LChild;
    int data;
    struct node* RChild;
}BSTNode;

#endif