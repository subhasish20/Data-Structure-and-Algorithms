#include<stdio.h>

int main()
{
    int n, i, j, key;
    printf("Enter how many element you want to apply linear search :");
    scanf("%d",&n);
    int array[n];

    printf("Enter the elements :");
    for(i = 0; i < n; i++)
    {
        scanf("%d",&array[i]);
    }

    printf("Enter the element you want to search :");
    scanf("%d",&key);

    for(i = 0; i < n; i++)
    {
        if(array[i] == key)
        {
            printf("element %d is found in the %d index ", array[i], i+1);
            return 0;
        }
    }
    printf("element is not found in the array ");
    return 0;
}