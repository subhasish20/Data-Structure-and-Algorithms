#include<stdio.h>
#include<stdlib.h>     
#define MAX_SIZE 100


int* BubbleSort(int n, int array[n]) {
    int i, j, temp;
    int* sortedArray = (int*)malloc(n * sizeof(int)); // Dynamically allocate memory

    // Copy input array to sortedArray
    for(i = 0; i < n; i++) {
        sortedArray[i] = array[i];
    }

    // Bubble sort on sortedArray
    for(i = 0; i < n; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(sortedArray[j] > sortedArray[j + 1]) {
                temp = sortedArray[j];
                sortedArray[j] = sortedArray[j + 1];
                sortedArray[j + 1] = temp;
            }
        }
    }

    return sortedArray;  // Return the pointer to the sorted array
}

int main() {
    int i, n;
    int array[MAX_SIZE];
    
    printf("Enter how many elements you want to apply bubble sort: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    int* sortedArray = BubbleSort(n, array);  // Get the sorted array
    
    printf("The sorted array is:\n");
    for(i = 0; i < n; i++) {
        printf("%d\t", sortedArray[i]);
    }

    free(sortedArray);  // free the memory allocation 

    return 0;
}
