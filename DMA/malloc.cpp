#include<iostream>
using namespace std;

int main()
{
    int size,i;
    cout<<"Enter the memory size :";
    cin>>size;

    int *memory = (int*) malloc(size * sizeof(int));

    if(memory == NULL)
    {
        cout<<"Memory has not created !!";
    }
    else
    {   
        cout<<"Enter the elements :";
        for ( i = 0; i < size; i++)
        {
            cin>>memory[i];
        }
        
    }
    cout<<"The elements are :";
    for(i = 0; i < size; i++)
    {
        cout<<" "<<memory[i];
    }

    free(memory);
    return 0;
}