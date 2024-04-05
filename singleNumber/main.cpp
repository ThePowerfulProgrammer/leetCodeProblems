#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        vector<int>::iterator i;
        for (i = nums.begin(); i != nums.end(); ++i)
            {
                if (dict.find(*i) != dict.end())
                    {

                        dict[*i] += 1;
                    }
                else
                    {
                        dict[*i] = 1;
                    }
            }

        int single = nums[0];


        for (const auto& [key,value] : dict)
            {
                if (value < dict[single])
                    {
                        single = key;
                    }
            }

        return single;
    }
private:
    map<int,int> dict;

};

int main()
{
    cout << "Single number using bit manipulation!" << endl;

    int x = 5; // 101
    int y = 19; // 10011
    int z = x && y; // 101 && 10011
                    // 00101
                    // 10011
                    // 00001

    cout << x << endl;
    cout << y << endl;
    cout << (x ^ y)  << endl;
    cout << z << endl;

    vector<int> nums({2,2,3,3,4,4,5,1,1});

    Solution s1;
    cout << s1.singleNumber(nums);
    return 0;
}
