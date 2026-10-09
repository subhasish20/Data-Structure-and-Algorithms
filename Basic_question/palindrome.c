#include <stdio.h>

int main(void)
{
    int number;
    printf("Enter a number to check palindrome :");
    scanf("%d", &number);

    int reverse, remainder = 0;
    int original_number = number;

    while(number > 0)
    {
        remainder = number % 10;
        reverse = reverse * 10 + remainder;
        number = number / 10;
    }

    if(reverse == original_number)
        printf("The given number is palindrome\n");
    else
        printf("The given number is not palindrome\n");

    return 0;
}
