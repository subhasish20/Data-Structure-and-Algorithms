#include <stdio.h>
#include <stdlib.h>


struct Node
{
    int data;              // stores the value
    struct Node* next;     // pointer to next node
};

// head initially points to NULL (empty list)
struct Node* head = NULL;


int insertAtBegining(int value)
{
    // allocate memory for new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // store value in the node
    newNode->data = value;
    // link new node to current head
    newNode->next = head;
    // update head to new node
    head = newNode;
}


void DisplayList()
{
    struct Node* temp = head;  // start from head

    if (temp == NULL) // for empty list
    {
        printf("List is empty !!!\n");
        return;
    }

    printf("The elements of the list are:\n");

    // move through the list until NULL means till the last node
    while (temp != NULL)
    {
        printf("%d ---> ", temp->data); // print current node value
        temp = temp->next;              // move to next node
    }

    printf("NULL\n");
}


void freeList()
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
    int n, value;

    printf("Enter how many elements you want to insert: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);

        insertAtBegining(value);  
    }

    DisplayList(); // calling the Display function;


    freeList(); // free the memory

    return 0;
}
