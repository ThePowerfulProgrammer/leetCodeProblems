#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        vector<int>::iterator i;
        for (i = nums.begin(); i != nums.end(); ++i)
            {
                cout << &(*i) << endl;
            }
        return 1;
    }
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
    cout << z << endl;

    vector<int> nums({1,2,2,3,3,4,5});

    Solution s1;
    s1.singleNumber(nums);
    return 0;
}
