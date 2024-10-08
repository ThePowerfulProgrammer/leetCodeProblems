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
        vector<vector<int>> subset;

        subset.push_back({});
        vector<int>::iterator numsStart;
        vector<int>::iterator numsEnd;
        numsEnd = nums.end();

        for (int i=0;i<nums.size(); i++)
            {
                numsStart = nums.begin() + i;
                vector<int> tempSet(numsStart, numsEnd);
                vector<int> tempSetBackwards;


                for (int j=i+1;j<nums.size(); j++)
                    {
                        subset.push_back(tempSet);
                        tempSet.pop_back();

                    }
                subset.push_back(tempSet);

            }


        return subset;
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
