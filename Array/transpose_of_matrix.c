#include<stdio.h>
#define MAX 20
int matrix[MAX][MAX];
int row, column, i, j;


int TransposeMatrix()
{
    return 0;
}

int DisplayMatrix(int row, int column, int matrix[MAX][MAX])
{
    printf("Before Transpose the matrix is :\n");
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < column; j++)
        {
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
int main()
{
    printf("Enter the row and column size of the matrix :\n");
    scanf("%d%d",&row,&column);

    printf("Enter the elements :\n");
    for(i = 0; i < row; i++)
    {
        printf("\nEnter the value of row no. %d",i+1);
        for(j = 0; j < column; j++)
        {
            printf("Enter the %d element ",j+1);
            scanf("%d",&matrix[i][j]);
        }
    }
    DisplayMatrix(row,column,matrix);

    return 0;
}