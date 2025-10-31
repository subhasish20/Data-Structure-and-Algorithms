#include<stdio.h>
#define MAX_SIZE 100        

int BubbleSort(int n,int array[n] )
{
    int i, j,temp;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if(array[j] > array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    return 0;
}

int main()
{   
    int i,  n;
    int array[MAX_SIZE];
    printf("Enter how many element you want apply bubble sort :");
    scanf("%d",&n);

    printf("Enter the elements :");
    for(i = 0; i < n; i++)
    {
        scanf("%d",&array[i]);
    }
    BubbleSort(n,array);
    printf("The sorted array is :\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t",array[i]);
    }

    return 0;
}