#include<stdio.h>

int factorial(int n)
{
    if(n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1); // recursive call
    }
}

int main()
{
    int number;
    printf("Enter the number :");
    scanf("%d",&number);

    if(number < 0)
    {
        printf("unable to find the factorial of the nagative number :");
    }
    else
    {
        printf("The factorial of %d  is %d",number,factorial(number));
    }

    return 0;
}