#include<stdio.h>

void addMatrix(int a[][10], int b[][10], int result[][10], int row, int col)
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

    int a[10][10], b[10][10], result[10][10];

    printf("\nEnter Matrix A values:\n");
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nEnter Matrix B values:\n");
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            printf("B[%d][%d] = ", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    addMatrix(a, b, result, row, col);

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
