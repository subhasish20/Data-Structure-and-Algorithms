#include<iostream>
#define MAX 100
using namespace std;

int i, j, k, size;
int array[MAX];


class solution
{
    public: 
            int DisplaySubarray(int array[], int size)
            {

                cout<<"the subarray of the given array are :\n";
                for( i = 0 ; i < size; i++)
                {
                    for(j = i; j < size; j++)
                    {
                        for(k = i; k <=j; k++)
                        {
                            cout<<array[k]<<" ";
                        }
                        cout<<endl;
                    }
                }

                return 0;
            }    
};
int main()
{
    cout<<"Enter how many elements you want to store :";
    cin>>size;
    cout<<"Enter the elements of the array :"<<endl;
    for(i = 0; i<size; i++)
    {
        cin>>array[i];
    }

    solution obj;
    obj.DisplaySubarray(array, size);


    return 0;
}