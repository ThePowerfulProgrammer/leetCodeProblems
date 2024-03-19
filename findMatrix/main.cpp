#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
You are given an integer array nums. You need to create a 2D array from nums satisfying the following conditions:

The 2D array should contain only the elements of the array nums.
Each row in the 2D array contains distinct integers.
The number of rows in the 2D array should be minimal.
Return the resulting array. If there are multiple answers, return any of them.

Note that the 2D array can have a different number of elements on each row.

*/


class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums)
    {

    }


};


bool vectorFind(vector<int> v, int i)
{
    // find i in v
    for (int num: v)
        {
            if (num == i)
                {
                    return true;
                }
        }
    return false;
}

int main()
{
    cout << "Creating a matrix!" << endl;

    unordered_map<int,int> dict;
    vector<int> nums = {1,2,2,4,5,5,5,3};

    for (const int i: nums)
        {
            if (dict.find(i) != dict.end())
                {
                    cout << "Already in dict, therefore increment" << endl;
                    int value = dict[i] + 1;
                    dict[i] = value;
                }
            else
                {
                    cout << "I have never seen this number in my entire life" << endl;
                    dict[i] = 1;
                }
        }

    for(const auto& pair:dict)
        {
            cout << pair.first << ":" << pair.second << endl;
        }

    return 0;
}
