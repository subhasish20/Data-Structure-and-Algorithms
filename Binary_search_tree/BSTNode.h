#ifndef BSTNODE_H
#define BSTNODE_H

typedef struct node {
    struct node* lchild;
    int data;
    struct node* rchild;
}Node;

#endif