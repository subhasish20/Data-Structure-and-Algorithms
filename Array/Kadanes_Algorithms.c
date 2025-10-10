#include<stdio.h>
#include<limits.h>
int main()
{
    int array[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(array) / sizeof(array[0]);

    int CurrentSum, MaxSum;
    CurrentSum = 0;
    MaxSum = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        CurrentSum += array[i];
        if(CurrentSum > MaxSum) // Check if he current sum is greater than maxsum or not if yes then assign in maxsum
        {
            MaxSum = CurrentSum;
        }
        if(CurrentSum < 0) // if the current sum is 0 then reset to 0;
        {
            CurrentSum = 0;
        }
    }
    printf("The maximum subarray sum is : %d",MaxSum);


    return 0;
}