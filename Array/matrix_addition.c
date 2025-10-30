#include<stdio.h>

void addMatrix(int row, int col, int a[row][col], int b[row][col], int result[row][col])
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

int main()
{
    int row, col, i, j;
    printf("Enter the row and column size : ");
    scanf("%d%d",&row,&col);

    int a[row][col];
    int b[row][col];
    int result[row][col];

    printf("Enter the elements of Matrix A:\n");
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            printf("A[%d][%d] = ", i, j);
            scanf("%d",&a[i][j]);
        }
    }

    printf("Enter the elements of Matrix B:\n");
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            printf("B[%d][%d] = ", i, j);
            scanf("%d",&b[i][j]);
        }
    }

    addMatrix(row, col, a, b, result);

    printf("\nResult Matrix:\n");
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
