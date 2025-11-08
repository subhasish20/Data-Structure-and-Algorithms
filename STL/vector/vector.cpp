#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int size;
    cout<<"Enter the size of the vector :";
    cin>>size;
    vector<int>vec(size);

    if(vec.size() == size) 
    {
        cout<<"Vector created successfully";
    }
    else
    {
        cout<<"Faild to create vector memory";
    }

    return 0;
}