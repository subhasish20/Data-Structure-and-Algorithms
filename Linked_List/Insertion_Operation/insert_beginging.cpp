#include<iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node* head = NULL;

Node* CreateNode(int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

int InsertAtBeginning(Node* newNode)
{
    newNode->next = head;
    head = newNode;
}

int PrintList()
{
    Node* temp;
    temp = head;
    while(temp != NULL)
    {
        cout<<"->"<<temp->data;
        temp = temp->next;
    }

    return 0;
}

int freeList()
{
    struct Node* temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;   // move head to next node
        free(temp);          // delete old head
    }
}

int main()
{
    Node* node = CreateNode(10);
    InsertAtBeginning(node);

    node = CreateNode(20);
    InsertAtBeginning(node);

    PrintList();
    
    freeList();

    return 0;
}