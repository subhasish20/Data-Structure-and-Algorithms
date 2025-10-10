#include<iostream>
#include<vector>
using namespace std;

class solution
{
public:
    int DisplayElement(vector<int>&nums)
    {
        cout<<"the entered elements are :\n";
        for(int i = 0; i < nums.size(); i++)
        {
            cout<<" "<<nums[i];
        }
        return 0;

    }
    int removeElement(vector<int>& nums, int val) {
                int k = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != val)
            {
                nums[k] = nums[i];
                k++;
            }
        }
        cout<<k;
        return 0;
    }
};
        


int main()
{
    vector<int>nums;
    int val,size,element;
    cout<<"Enter how many elements you want to store :\n";
    cin>>size;
    cout<<"Enter the elements :\n";
    for(int i = 0; i < size; i++)
    {   
        cin>>element;
        nums.push_back(element);
        
    }
    solution sol;
    sol.DisplayElement(nums);

    cout<<"\nEnter which element you want to remove :";
    cin>>val;
    sol.removeElement(nums, val);
    
    return 0;
}