#include<stdio.h>

int main()
{
    int n;
    printf("Enter how many element you want to store ");
    scanf("%d",&n);
    int arr[n];

    printf("Enter the elements :\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }

    int window;
    printf("Enter the window size :\n");
    scanf("%d", &window);

    int winddowSum = 0, maxSum = 0;

    for(int i = 0; i < window; i++) // sum for first window
    {
        winddowSum += arr[i];
        maxSum = winddowSum; // assming that 1st window sum is the greater than all
    }

    for(int i = window; i < n; i++)
    {
        winddowSum += arr[i] - arr[i - window];
        if(maxSum < winddowSum) // if the first window is not greater then assing the current window sum 
        {
            maxSum = winddowSum;
        }
    }
    printf("Maximum sum of subarrys of size %d = %d\n",window,maxSum);


    return 0;
}