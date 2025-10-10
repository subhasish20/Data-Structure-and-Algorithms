// remove the duplicated elements from an array
#include<iostream>
#include<vector>
using namespace std;

int i, size;
int value = 0;


class Solution {
public:
    int removeDuplicates(vector<int>& vec) {
        if (vec.empty()) return 0;
        int j = 0;
        for (int i = 1; i < vec.size(); ++i) {
            if (vec[i] != vec[j]) {
                j++;
                vec[j] = vec[i];
            }
        }
        return j + 1;
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

    Solution  sol;
    sol.removeDuplicates(vec);

    return 0;
}

