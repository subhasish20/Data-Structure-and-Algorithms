#include<stdio.h>
#define MAX_SIZE 100


void Merge(int arr[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = 0; // for point the index of temp
    int temp[MAX_SIZE];

    // Comparing the both halves for store the smaller element
    while(i <= mid && j <= high)
    {
        if(arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++; // for incrementing the index for temp array
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    // for the remaining element of left side
    while(i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    // for the remaining element of right side
    while(j <= high)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // now re-inserting it in the base array
    int index = 0;
    for(int x = low; x <= high; x++)
    {
        arr[x] = temp[index];
        index++;
    }


}

void MergeSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int mid = (low + high)/2;
        MergeSort(arr, low, mid); // it will divide  the left side of the array
        MergeSort(arr, mid + 1, high); // it will divide the right size of the array
        Merge(arr, low, mid, high); // calling the merge() for sorting 
    }
}

int main()
{
    int n;
    int arr[MAX_SIZE];
    printf("Enter how many element you want to sort :");
    scanf("%d",&n);

    printf("Enter the elements :");
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }

    MergeSort(arr, 0, n-1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}