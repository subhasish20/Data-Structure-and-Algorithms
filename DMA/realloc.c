#include<stdio.h>
#include<stdlib.h>

int main()
{
    int size, i, new_size;
    int *memory;

    printf("Enter the size of the memeory :");
    scanf("%d",&size);
    memory = (int*) malloc(size * sizeof(int));
    if(memory == NULL)
    {
        printf("Memory creation failed");
    }
    else
    {   
        printf("\nEnter the elments of the array : ");
        for(int i = 0; i < size; i ++)
        {
            scanf("%d",&memory[i]);
        }
    }
    printf("\nThe elements of the array are :");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t",memory[i]);
    }
    printf("\nEnter the new memory size :");
    scanf("%d",&new_size);
    memory = (int*) realloc(memory, new_size * sizeof(int));
    if(memory == NULL)
    {
        printf("unable to create memory !!");

    }
    else
    {   
        printf("\nEnter the elments of the new array : ");
        for(int i = 0; i < new_size; i ++)
        {
            scanf("%d",&memory[i]);
        }
    }
    printf("The elements of the array are :\n");
    for (int i = 0; i < new_size; i++)
    {
        printf("%d\n",memory[i]);
    }

    free(memory);
    return 0;
}