#include<stdio.h>
#define MAX_SIZE 100
int main()
{
    int arr[MAX_SIZE];
    int size;
    printf("Enter how many element you want to store in array :");
    scanf("%d",&size);

    printf("Enter the elements :");
    for(int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Before reversing the array is ");
    for(int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }

    int left = 0;
    int right = size - 1;
    while(left < right)
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }
    printf("\nafter reversing the array is :");
    for(int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}