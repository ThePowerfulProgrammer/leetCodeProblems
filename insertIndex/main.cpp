#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int searchInsert(vector<int>& nums, int target)
{
    // initial search

    for (int i=0;i<nums.size();i++)
        {
            if (nums[i] == target)
                {
                    return i;
                }
        }

    // Search found nothing
    nums.push_back(target);
    std::sort(nums.begin(), nums.end());
    for (int i=0;i<nums.size();i++)
        {
            if (nums[i] == target)
                {
                    return i;
                }
        }
}

int main()
{
    vector<int> nums = {1,3,5,6};
    cout << searchInsert(nums,5) << endl;

    vector<int> numsLess = {1,3,5,6};
    cout << searchInsert(numsLess,2) << endl;
    return 0;
}
