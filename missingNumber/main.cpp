#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
    First -> sort
    Second -> determine range
    Third --> Binary search from i+1 to n-1
    Fourth --> Return value that was not found from step 3

    eg: {1,0,3}
*/


class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        std::sort(nums.begin(),nums.end());

        int range = nums.size() - nums.front(); // [0,range]

        for (int i=1;i<=range;i++)
            {

                bool flag = std::binary_search(nums.begin(),nums.end(),i);

                if (!flag)
                    {
                        return i;
                    }
            }

        return 0;

    }
};

int main()
{
    cout << "Hello world!" << endl;
    Solution s1;
    vector<int> nums = {0,1};
    cout << s1.missingNumber(nums) << endl;
    return 0;
}
