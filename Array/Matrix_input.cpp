#include<iostream>
using namespace std;

int main()
{
    int row,col,i,j;
    cout<<"Enter the row size :";
    cin>>row;
    cout<<"Enter the column size :"<<endl;
    cin>>col;
    int array[row][col];

    for(i = 0; i<row; i++)
    {
        for(j = 0; j < col; j++)
        {
            cout<<"Enter the value of "<<i+1<<"\t"<<j+1<<"  element"<<endl;
            cin>>array[i][j];
        }
    }

    cout<<"The elements of the matrix are :"<<endl;
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            cout<<"\t"<<array[i][j];
        }
        cout<<endl;
    }
}