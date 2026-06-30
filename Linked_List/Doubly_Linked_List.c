#include <stdio.h>
#include <stdlib.h>

// Structure definition
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// Function prototypes
Node* createNode(int data);
void insertBeginning(Node **head, int data);
void insertEnd(Node **head, int data);
void deleteBeginning(Node **head);
void deleteEnd(Node **head);
void displayForward(Node *head);
void displayBackward(Node *head);
void search(Node *head, int key);
void freeList(Node **head);

// Create a new node
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// Insert at beginning
void insertBeginning(Node **head, int data) {
    Node *newNode = createNode(data);

    newNode->next = *head;

    if (*head != NULL)
        (*head)->prev = newNode;

    *head = newNode;
}

// Insert at end
void insertEnd(Node **head, int data) {
    Node *newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node *temp = *head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Delete from beginning
void deleteBeginning(Node **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *temp = *head;
    *head = temp->next;

    if (*head != NULL)
        (*head)->prev = NULL;

    printf("Deleted: %d\n", temp->data);
    free(temp);
}

// Delete from end
void deleteEnd(Node **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *temp = *head;

    if (temp->next == NULL) {
        printf("Deleted: %d\n", temp->data);
        free(temp);
        *head = NULL;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    printf("Deleted: %d\n", temp->data);

    temp->prev->next = NULL;
    free(temp);
}

// Display forward
void displayForward(Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Forward: ");

    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");
}

// Display backward
void displayBackward(Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (head->next != NULL)
        head = head->next;

    printf("Backward: ");

    while (head != NULL) {
        printf("%d ", head->data);
        head = head->prev;
    }

    printf("\n");
}

// Search an element
void search(Node *head, int key) {
    int position = 1;

    while (head != NULL) {
        if (head->data == key) {
            printf("%d found at position %d\n", key, position);
            return;
        }

        head = head->next;
        position++;
    }

    printf("%d not found.\n", key);
}

// Free the entire list
void freeList(Node **head) {
    Node *temp;

    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

// Main function
int main() {
    Node *head = NULL;
    int choice, value;

    while (1) {
        printf("\n===== Doubly Linked List =====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display Forward\n");
        printf("6. Display Backward\n");
        printf("7. Search\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBeginning(&head, value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(&head, value);
                break;

            case 3:
                deleteBeginning(&head);
                break;

            case 4:
                deleteEnd(&head);
                break;

            case 5:
                displayForward(head);
                break;

            case 6:
                displayBackward(head);
                break;

            case 7:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(head, value);
                break;

            case 8:
                freeList(&head);
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
