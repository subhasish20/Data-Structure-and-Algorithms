#include<stdio.h>

int SubstractMatrix(int row, int col, int MatrixA[row][col], int MatrixB[row][col], int ResultMatrix[row][col] )
{
    int i, j;
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            ResultMatrix[i][j] = MatrixA[i][j] - MatrixB[i][j];
        }
    }
    printf("The resul matrix after substraction is :\n");
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            printf("%d\t",ResultMatrix[i][j]);
        }
        printf("\n");

    }    

    return 0;
}
int main()
{
    int row, col, i, j;
    printf("Enter the row size and column size :");
    scanf("%d%d",&row,&col);

    int MatrixA[row][col],MatrixB[row][col],ResultMatrix[row][col];

    printf("Enter the element of matrix A :");
    for ( i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            scanf("%d",&MatrixA[i][j]);
        }
    }

    printf("The matrix A is :\n");
    for ( i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            printf("%d",&MatrixA[i][j]);
        }
    }    

    printf("Enter the element of matrix B :");
    for ( i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            scanf("%d",&MatrixB[i][j]);
        }
    }
    
    SubstractMatrix(row, col, MatrixA, MatrixB, ResultMatrix);
    return 0;
}