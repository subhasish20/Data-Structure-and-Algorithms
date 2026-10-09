#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int number;
    printf("Enter a number :");
    scanf("%d", &number);

    int remainder = 0;
    int original_number = number;

    int armstrong = 0;

    while (number > 0)
    {
        remainder = number % 10;
        armstrong = (int)armstrong + remainder * remainder * remainder;
        number = number / 10;
    }
    if(original_number == armstrong)
        printf("Given number %d is armstrong number \n ",original_number);
    else
        printf("Given number is not armstrong number\n");




    return EXIT_SUCCESS;
}
