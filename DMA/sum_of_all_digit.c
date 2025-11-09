#include<stdio.h>
#include<stdlib.h>

int main()
{
    int size;
    int sum = 0;
    printf("Enter how many number you want to find sum :");
    scanf("%d",&size);

    int *memory = (int*)malloc(size * sizeof(int));
    if(memory == NULL)
    {
        printf("Memory creation failed ");
    }
    else 
    {
        printf("Enter the elements :\n");
        for(int i = 0; i < size; i++)
        {
            scanf("%d",&memory[i]);
        }
    }
    printf("The elemets are :\n");
    for(int i = 0; i < size; i++)
    {
       printf("%d\t",memory[i]);
    }
    for(int i = 0; i < size; i++)
    {
        sum += memory[i];
    }
    printf("\nThe sum of all elements is : %d",sum);
}