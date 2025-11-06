#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n;  // Base case: Fibonacci(0) = 0, Fibonacci(1) = 1
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);  // Recursive call
    }
}

int main() {
    int num;

    // Take user input
    printf("Enter the number of terms in Fibonacci series: ");
    scanf("%d", &num);

    printf("Fibonacci series: ");
    for (int i = 0; i < num; i++) {
        printf("%d ", fibonacci(i));  // Call the fibonacci function for each term
    }

    printf("\n");

    return 0;
}
