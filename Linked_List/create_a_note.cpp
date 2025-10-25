#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node* head = nullptr;
Node* CreateNode(int x)
{
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = nullptr;

    return newNode;
}
void InsertAtBeginning(int x)
{
    Node* AtBeginning = CreateNode(x);
    AtBeginning->next = head;
    head = AtBeginning; 
}
void PrintLinkedList(int x)

{
    Node* current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}


int main()
{
    int n,x;
    cout<<"Enter how many numbers you want to store :";
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cout<<"Enter the element :";
        cin>>x;
        InsertAtBeginning(x);
        PrintLinkedList(x);
    }
}