#include<iostream>
using namespace std;

class Solution
{
    public:
    int merge(int* array1, int* array2, int size1, int size2)
    {

        int val1, val2;
        int i , j, sum;
        cout<<"Enter how many element of array 1 you want to merge :";
        cin>>val1;
        cout<<"Enter how many element of the array 2 you want to merge :";
        cin>>val2;
        int finalArray[size1+size2];
        for(i = 0; i < val1 ; i++)
        {
            finalArray[i] = array1[i];
        }

        for (int j = 0; j < val2; j++, i++) {
            finalArray[i] = array2[j];
        }
        sum = val1 + val2;
        cout<<"The final merge array is :"<<endl;
        for(int i = 0; i < sum; i++)
        {
            cout<<finalArray[i]<<"  ";
        }

        return 0;
    }
};

int main()
{
    int size1, size2;
    cout<<"Enter how many number you want to store in the array 1 :";
    cin>>size1;
    int array1[size1];
    for(int i = 0; i < size1; i++)
    {   
        cout<<"Enter the "<< i+1 << " element :"<<endl;
        cin>>array1[i];
    }
    cout<<"Enter the how many numbers you want to store in the array 2 :";
    cin>>size2;

    int array2[size2];
    for(int i = 0; i < size2; i++)
    {
        cout<<"Enter the "<< i+1 << " element :"<<endl;
        cin>>array2[i];
    }

    Solution sol;
    sol.merge(array1, array2, size1, size2);

    return 0;
}