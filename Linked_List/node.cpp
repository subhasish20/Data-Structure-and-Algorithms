#include<iostream>
#include<stdlib.h>
using namespace std;

void create();
void display();
void freeList();

struct node
{
    int data;
    struct node* next;
};

struct node* start = NULL,*temp,*newNode;

int main()
{
    int choice;
    do
    {
        cout<<"\n-----------Linked list menu-------------"<<endl;
        cout<<"Press 1 to Create"<<endl;
        cout<<"Press 2 to Display"<<endl;
        cout<<"Press 3 to insert at first"<<endl;
        cout<<"Press 4 to insert in middle"<<endl;
        cout<<"Press 5 to insert at last"<<endl;
        cout<<"Press 6 to exit"<<endl;
        cin>>choice;
    switch(choice)
    {
        case 1:create();
        break;
        case 2:display();
        break;
        case 6:freeList();
        default:
        cout<<"Thank you visit again"<<endl;
    }

    } while (choice != 6);


    return 0;
    
}

void create()
{   
    int element;
    char ch;
    start = (struct node*)malloc(sizeof(struct node));
    cout<<"Enter the element :"<<endl;
    cin>>element;
    start->data = element;
    start->next = NULL;
    temp = start;
    cout<<"do you eant to continue :(y/n)";
    cin>>ch;

    while (ch == 'y' || ch == 'Y')
    {
        cout<<"Enter the next element :";
        cin>>element;
        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = element;
        newNode->next = NULL;
        temp->next = newNode;
        temp = temp->next;
        cout<<"Do you want to continue :";
        cin>>ch;
    }
}

void display() {
    if (start == NULL) {
        cout << "The list is empty." << endl;
        exit(0);
    }

    struct node* temp = start;
    cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void freeList()
{
    temp = start;
    struct node* nextNode;

    while (temp != NULL) {
        nextNode = temp->next;  // Save the next node
        free(temp);             // Free the current node
        temp = nextNode;        // Move to the next node
    }

    start = NULL;  // After freeing all nodes, set start to NULL
    cout << "All memory freed successfully!" << endl;
}