#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    printf("Enter the size of the memory :");
    scanf("%d",&n);
    int *memory = (int*) malloc(n * sizeof(int));
    if(memory == NULL)
    {
        printf("Memory creation failed");
    }
    else
    {   
        printf("Enter the elments of the array : ");
        for(int i = 0; i < n; i ++)
        {
            scanf("%d",&memory[i]);
        }
    }
    printf("The elements of the array are :");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",memory[i]);
    }

    free(memory);
    

    return 0;
}