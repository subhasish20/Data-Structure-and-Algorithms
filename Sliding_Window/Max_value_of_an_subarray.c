#include<stdio.h>

int main()
{
    int n;
    printf("Enter how many element you want to store in the array :");
    scanf("%d",&n);

    int arr[n];
    printf("Enter the elements :");
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }


    int max;
    int k = 3;

    for(int i = 0; i < n - k; i++)
    {
        max = arr[i];

        for(int j = i; j < i + k; j++)
        {
            if(arr[j] > max)
            {
                max = arr[j];
            }
        }
        printf("%d\t",max);
    }

    return 0;
}