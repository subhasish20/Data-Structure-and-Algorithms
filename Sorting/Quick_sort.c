#include<stdio.h>

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


int Partition(int A[], int low, int high)
{
    int Pivot = A[low];
    int i = low+1;
    int j = high;
    while(i < j)
    {
        while(A[i] <= Pivot)
        {
            i++;
        }
        while (A[j] > Pivot)
        {
            j--;
        }
        if(i < j)
        {
            Swap(&A[i],&A[j]);
        } 
    }
        Swap(&A[low],&A[j]);

    return j;
}
void QuickSort(int A[], int low, int high)
{
    int j;
    if(low < high)
    {
        j = Partition(A, low, high);
        QuickSort(A, low, j-1);
        QuickSort(A, j+1, high);

    }

}

int main()
{
    int i,j,n;
    printf("enter how many element you want to sort :");
    scanf("%d",&n);
    int A[n];

    printf("Enter the elements :\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d",&A[i]);
    }

    QuickSort(A, 0, n-1);
    printf("The sorted array is :\n");
    for ( i = 0; i < n; i++)
    {
        printf("    %d  ",A[i]);
    }
    
    return 0;
}