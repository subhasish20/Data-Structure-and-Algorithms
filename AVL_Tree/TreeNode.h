#ifndef  TREENODE_H
#define TREENODE_H

#include <stdlib.h>
typedef  struct Node Node;
struct Node
{
    int data;
    Node* left;
    Node* right;
    int height;
};

#endif /*TREENODE_H */
