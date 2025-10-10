#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
    void bubbleSort(vector<int>& nums)
    {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (nums[j] > nums[j + 1])
                {
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }

        cout << "\nArray after Bubble Sort: ";
        for (int i = 0; i < n; i++)
            cout << nums[i] << " ";
        cout << endl;
    }
    int removeDuplicates(vector<int>&nums)
    {   
        int k = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(k < 2 || nums[i] != nums[k -2])
            {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
    int DisplayFinalArray(vector<int>&nums,int k)
    {
        cout<<"The final array is \n";
        for(int i = 0 ; i < k; i++)
        {
            cout<<" "<<nums[i];
        }
        return 0;
    }
};

int main()
{
    vector<int> nums;
    int n, element;

    cout << "Enter how many elements you want to store: ";
    cin >> n;

    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> element;
        nums.push_back(element);
    }

    cout << "Before sorting: ";
    for (int i = 0; i < n; i++)
        cout << nums[i] << " ";

    Solution sol;
    sol.bubbleSort(nums);   
    int k = sol.removeDuplicates(nums);
    sol.DisplayFinalArray(nums, k);

    return 0;
}
