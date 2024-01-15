#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.



Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.


Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
*/

bool isElementInVector(const std::vector<int>& vec, int element)
{
    return std::find(vec.begin(), vec.end(), element) != vec.end();
}

void removeElement(vector<int> nums, int elementToRemove)
{
    auto it1 = std::find(nums.begin(),nums.end(), elementToRemove);
    if (it1 != nums.end())
        {
            nums.erase(it1);
        }
}

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> intersection;
        for (int i=0;i<nums1.size();i++)
            {
                // determine if element matches
                if (isElementInVector(nums2,nums1[i]))
                    {
                        intersection.push_back(nums1[i]);
                        removeElement(nums1,nums1[i]);
                        removeElement(nums2,nums1[i]);
                    }
            }

        return intersection;
    }
};

int main()
{
    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {9,4,9,8,4};
    Solution s1;
    s1.intersect(nums1,nums2);
    return 0;
}
