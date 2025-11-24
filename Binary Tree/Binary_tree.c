#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int main()
{
    printf("----Welcome to Binary Tree Insertion Code---------");
    int value, choice;

    printf("Enter the root node :");
    scanf("%d",&value);

    struct Node* root = createNode(value);

    while(1)
    {
        printf("\n Where to insert :");
        printf("\n Press 1. Left of the root node :");
        printf("\n Press 2. Right of the root node :");
        printf("\n Press 3. Left of the left child node :");
        printf("\n Press 4. Right of the left child node :");
        printf("\n Press 5. left of the right child node :");
        printf("\n Press 6. Right of the right child node :");
        printf("\n Press 7. Exit :");
        printf("\n Enter your choice :");
        scanf("%d",&choice);

        if(choice == 7)
        {
            break;
        }
        printf("Enter the value :");
        scanf("%d",&value);
        switch(choice)
        {
            case 1:
            if(root->left == NULL)
            {
                root->left = createNode(value);

            }
            else 
            {
                printf("Already filled that place !!");
            }
            break;
            case 2:
            if(root->right == NULL)
            {
                root->right = createNode(value);
            }
            else
            {
                printf("Already filled that place !!");
            }
            break;
            case 3:
            if(root->left == NULL)
            {
                printf("Left side of the root node does not exits !!");
            }
            else if(root->left->left == NULL)
            {
                root->left->left = createNode(value);
            }
            else 
            {
                printf("Already filled that place !!");
            }
            break;
            case 4:
            if(root->left == NULL)
            {
                printf("right side of the root node does not exits !!");
            }
            else if(root->left->right == NULL)
            {
                root->left->right = createNode(value);
            }
            else 
            {
                printf("Already filled that place !!");
            }
            break;
            case 5:
            if(root->right == NULL)
            {
                printf("right side of the root node does not exits !!");
            }
            else if(root->right->left == NULL)
            {
                root->right->left = createNode(value);
            }
            else 
            {
                printf("Already filled that place !!");
            }
            break;
            case 6:
            if(root->right == NULL)
            {
                printf("right side of the root node does not exits !!");
            }
            else if(root->right->right == NULL)
            {
                root->right->right = createNode(value);
            }
            else 
            {
                printf("Already filled that place !!");
            }
            break;
            default:printf("Invalid choice \n");            
        }
    }
    printf("\n Binary tree created successfully");

    return 0;
}