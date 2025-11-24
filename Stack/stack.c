#include<stdio.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;
int n;


int PUSH()
{
    int element;
    if(top >= n - 1)
    {
        printf("Stack overflow !!");
    }
    else 
    {
    printf("Enter the element to push :");
    scanf("%d",&element);
    top++;
    stack[top] = element;
    printf("%d pushed to stack\n",element);
    }

    return 0;
}
int POP()
{
    if(top == -1)
    {
        printf("Stack underflow !!\n");
    }
    else
    {
        printf("%d popped successfully !!\n",stack[top]);
        top--;
    }

    return 0;
}

int DISPLAY()
{
    int i;
    if(top == -1)
    {
        printf("stack is empty !!");
    }
    else 
    {
        printf("The elements of the stack are :\n");
        for(i = top; i >= 0; i--)
        {
            printf("%d\n",stack[i]);
        }
    }
    return 0;
}

int main()
{
    int ch;
    printf("-------------Welcome to Stack Data Structure----------------");
    printf("\nEnter the size of the stack :");
    scanf("%d",&n);
    do
    {
        printf("---------------Stack menu---------------");
        printf("\n Press 1 : PUSH");
        printf("\n Press 2 : POP");
        printf("\n Press 3 : DISPLAY");
        printf("\n Press 4 : Exit");
        printf("\n Enter your choice :");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: PUSH();
            break;
            case 2: POP();
            break;
            case 3: DISPLAY();
            break;
            case 4: printf("Exiting the program !! Thank you visit again !!");
            break;
            default:printf("Invalid choice !! Try again.....");
        }
    }while(ch != 4);


    return 0;
}