#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

int InsertAtLocation(int value, int location)
{

    // Node Creation
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // if location = 1 the insert at begining
    if(location == 1)
    {
        newNode->next = head;
        head = newNode;
        return 0;
    }

    struct Node* temp = head; // storing the head in temp for traversing
    // traversing to find the location
    for(int i = 1; i < location - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if(temp == NULL)
    {
        printf("Invalid location !!");
        return 0;
    }
    newNode->next = temp->next; // new node will store the address of the next node
    temp->next = newNode;// next node will connect here 

    return 0;

}

int DisplayList()
{
    struct Node* temp = head;

    if(temp == NULL)
    {
        printf("The given list is empyt !!");
        return 0;
    }
    printf("The elements of the list are :\n");
    while(temp != NULL)
    {
        printf("%d--->",temp->data);
        temp = temp->next;
    }
    printf("\n");

    return 0;
}

void FreeList()
{
    struct Node* temp;
    while(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    // Create initial list 10, 20, 30, 40
    InsertAtLocation(10, 1);
    InsertAtLocation(20, 2);
    InsertAtLocation(30, 3);
    InsertAtLocation(40, 4);

    DisplayList();

    int value, location;
    printf("\nEnter the element you want to insert: ");
    scanf("%d", &value);

    printf("Enter the position where you want to insert: ");
    scanf("%d", &location);

    InsertAtLocation(value, location); // calling the function again to insert at the give location

    //  Print final list
    printf("\nUpdated List:\n");

    DisplayList(); 

    FreeList();

}