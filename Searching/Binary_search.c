#include<stdio.h>

int main()
{
    int array[] = {10, 20, 30, 40, 50, 60};
    int low, high, mid, key;

    printf("Enter the element you want to search :");
    scanf("%d",&key);

    low = 0;
    high = 5; // high = n - 1 i.e. 6 - 1 = 5
    while(low <= high)
    {
        mid = (low + high)/2;
        if(array[mid] == key)
        {
            printf("element %d found in the %d index ", array[mid],mid);
            return 0;
        }
        else if(array[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }       
    }
        printf("element is not present in the array ");
    return 0;
}