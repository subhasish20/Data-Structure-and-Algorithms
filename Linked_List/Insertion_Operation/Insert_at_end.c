#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;           // data part
    struct Node* next;  // next part
};

struct Node* head = NULL;


int InsertAtEnd(int value)
{

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;     // store the value
    newNode->next = NULL;      // new node will be last, so next = NULL

    // CASE 1 → If list is empty, new node becomes head
    if (head == NULL)
    {
        head = newNode;
        return 0;              // exit from the  function
    }

    // CASE 2 → Traverse to the last node
    struct Node* temp = head;
    while (temp->next != NULL) // move until last node
    {
        temp = temp->next;
    }

    // attach new node at the end
    temp->next = newNode;
}


void DisplayList()
{
    struct Node* temp = head;

    // If no elements
    if (temp == NULL)
    {
        printf("List is empty !!\n");
        return;
    }

    printf("The elements of the list are:\n");

    while (temp != NULL)
    {
        printf("%d ---> ", temp->data);
        temp = temp->next;   // move to next node
    }

    printf("\n");        // end of list
}

void freeList()
{
    struct Node* temp;

    while (head != NULL)
    {
        temp = head;         // store current head
        head = head->next;   // move head to next node
        free(temp);          // delete old head
    }
}


int main()
{
    int n, value;

    printf("Enter how many elements you want to insert: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);

        InsertAtEnd(value);  
    }

    DisplayList();

    freeList();

    return 0;
}
