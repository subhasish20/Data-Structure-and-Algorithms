// remove the duplicated elements from an array
#include<iostream>
#include<vector>
using namespace std;

int i, size;
int value = 0;


class solution
{
    public:
        int RemoveDuplicate(vector<int>vec)
        {
            for(i = 0; i < vec.size(); i++)
            {
                if(vec[i] == i+1)
                {
                    
                } 
            }
            for( i = 0; i < vec.size(); i++)
            {
              cout<<vec[i];  
            }

            return 0;
        }
            
};

int main()
{
    vector<int>vec;

    cout<<"enter the size of array :";
    cin>>size;
    cout<<"Enter the elements";
    for (i = 0; i < size; i++)
    {   
        cin>>value;
        vec.push_back(value);
        value = 0;
    }

    solution  sol;
    sol.RemoveDuplicate(vec);

    return 0;
}

