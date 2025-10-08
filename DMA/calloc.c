#include<stdio.h>
#include<stdlib.h>

int main()
{
    int size, i;
    int *memory;


    printf("Enter the size of the memeory :");
    scanf("%d",&size);
    memory = (int*) calloc(size, sizeof(int));
    if(memory == NULL)
    {
        printf("Memory creation failed");
    }
    else
    {   
        printf("Enter the elments of the array : ");
        for(int i = 0; i < size; i ++)
        {
            scanf("%d",&memory[i]);
        }
    }
    printf("The elements of the array are :");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t",memory[i]);
    }

    free(memory);
    return 0;
}