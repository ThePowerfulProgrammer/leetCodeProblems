#include <iostream>
#include <vector>
using namespace std;

/**
Given an array nums of unique integers, return all possible subsets of nums.

The solution set must not contain duplicate subsets. You may return the solution in any order.

Example 1:

Input: nums = [1,2,3]

Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:

Input: nums = [7]

Output: [[],[7]]

Example 3:
Input: nums = [1,2,3,4]

Output: [[], [1], [2], [3], [1,2], [1,3], [1,2,3], [1,2,3,4], [1,4], [2,3], [2,4], [3,4]]


*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        // Choice -> Constraints -> Goal
        dfsAdd(nums,0);
        return res;
    }

private:
    vector<vector<int>> res; // 3d solution
    vector<int> subset;


    void dfsAdd(vector<int>&nums,int index)
    {
        if (index == nums.size())
            {
                res.push_back(subset);
                return;
            }

        subset.push_back(nums[index]);
        dfsAdd(nums, index+1);

        subset.pop_back();
        dfsAdd(nums,index+1);
    }

};


int main()
{
    cout << "Subsets using backtracking?!" << endl;

    Solution s1;
    vector<int> nums = {1,2,3};
    vector<vector<int>> matrix = s1.subsets(nums);

    cout << "Matrix Size: " << matrix.size() << endl;
    for (int i = 0;i<matrix.size(); i++)
        {
            for (int j = 0; j<matrix[i].size(); j++)
                {
                    cout << matrix[i][j] << ", ";
                }
            cout << endl;
        }
    return 0;
}
