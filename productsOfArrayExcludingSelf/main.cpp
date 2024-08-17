#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;

/*
Given an integer array nums, return an array output where output[i] is the product of all the elements of nums except nums[i].

Each product is guaranteed to fit in a 32-bit integer.


O(n) time without using the division operation?

*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        vector<int> result = {};
        if (std::find(nums.begin(), nums.end(), 0) == std::end(nums))
            {
                // Using the std lib && cmath && accumulate with function object to multiply all values in nums
                int product = std::accumulate(nums.begin(), nums.end(),1, std::multiplies<int>());

                for (int i=0;i<nums.size();i++)
                    {
                        if (nums[i] != 0)
                            {
                                result.push_back(product/nums[i]);
                            }
                        else
                            {
                                result.push_back(0);
                            }

                    }
                return result;
            }

        // 0 is in our vector
        for (int i=0;i<nums.size();i++)
            {
                int product = 1;
                for (int j=0;j<nums.size();j++)
                    {
                        if (i != j)
                            {
                                product *= nums[j];
                            }
                    }
                result.push_back(product);
            }
        return result;
    }


        // O(n)
        vector<int> productExceptSelf_V2(vector<int>& nums)
        {
            vector<int> result(nums.size(), 1);

            int left_product = 1;
            for (int i=0;i<nums.size(); i++)
                {
                    result[i] = left_product;
                    left_product *= nums[i];
                }

            // 1, 1, 2, 6,

            int right_product = 1;
            for (int i=nums.size()-1;i>=0;i--)
                {
                    result[i] *= right_product;
                    right_product *= nums[i];
                }

            return result;
        }

};


int main()
{
    cout << "Using the std lib && cmath && accumulate with function object" << endl;
    vector<int> v = {1,2,4,6};
    int product = std::accumulate(v.begin(), v.end(),1, std::multiplies<int>());
    cout << product << endl;


    Solution s1;
    vector<int> values = {-1,0,1,2,3};
    vector<int> nums = s1.productExceptSelf(values);
    for (int i: nums)
        {
            cout << i << ", ";
        }
    cout << "\n";

        //
    vector<int> values2 = {1,2,3,4};
    vector<int> numsV2 = s1.productExceptSelf_V2(values2);
    for (int i: numsV2)
        {
            cout << i << ", ";
        }


    return 0;
}
