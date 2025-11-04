/*
write a program to find the average temp of each three days of 7 days of a month continouly using sliding window
*/

#include<stdio.h>
#define MAX_SIZE 100
#include <stdio.h>

void avgTemp(int days, int window, int arr[])
{
    int avg_temp = 0;

    // compute sum of first window
    for (int i = 0; i < window; i++)
        avg_temp += arr[i];

    printf("Average of days 1 to %d = %.2f\n", window, (float)avg_temp / window);

    // slide the window
    for (int i = window; i < days; i++)
    {
        avg_temp = avg_temp - arr[i - window] + arr[i];
        printf("Average of days %d to %d = %.2f\n",i - window + 2, i + 1, (float)avg_temp / window);
    }
}
/*
avg_temp = avg_temp - arr[i - window] + arr[i]
          = 60 - arr[3 - 3] + arr[3]
          = 60 - arr[0] + arr[3]
          = 60 - 10 + 40
          = 90

*/
/*
i	window	Expression(i - window +2 )	Value	Human meaning
3	3	    3 - 3 + 2	                2	    start = day 2
4	3	    4 - 3 + 2	                3	    start = day 3
5	3	    5 - 3 + 2	                4	    start = day 4
6	3	    6 - 3 + 2	                5	    start = day 5
*/


int main()
{
    int days = 7;
    int arr[days];
    int window =3;
    int i;
    printf("Enter the temp of 7 days :");
    for(int i = 0; i < days; i++)
    {
        scanf("%d",&arr[i]);
    }
    int avg_temp = 0;
    
    avgTemp(days, window, arr);

    return 0;
}