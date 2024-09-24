#include <iostream>
#include <vector>

using namespace std;

/**
nums = {-1,0,2,4,6,8}
target = 4

Approach:
    Find middle if not target, check which side to reduce so that we have a smaller
    list and repeat until we find target or until we exhaust list.


*/

class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int beginning = 0;
        int ending = nums.size()-1;


        while (beginning <= ending)
            {
                int midpoint = (beginning+ending)/2;

                if (nums[midpoint] == target)
                    {
                        return midpoint;
                    }
                else if (nums[midpoint] < target)
                    {
                        beginning = midpoint+1;
                    }
                else if (nums[midpoint] > target)
                    {
                        ending = midpoint-1;
                    }
            }

        return -1;
    }
};


int main()
{
    cout << "You are given an array of distinct integers nums, sorted in ascending order, and an integer target!" << endl;
    cout << "Implement a function to search for target within nums. If it exists, then return its index, otherwise, return -1." << endl;

    vector<int> nums = {-1,0,2,4,6,8};

    Solution s1;

    cout << s1.search(nums,-1) << endl;




    return 0;
}
