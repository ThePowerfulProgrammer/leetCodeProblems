#include <iostream>
#include <vector>

using namespace std;

/*Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Input: nums = [3,2,4], target = 6
Output: [1,2]
*/

vector<int> twoSum(const vector<int>& nums, int target) {
    if (nums.size() == 2)
        {
            return {0,1}
        }
    for (int i=0;i<nums.size();i++)
        {
            if (i != nums.size()-1)
                {
                    for (int j=i+1;j<nums.size();j++)
                        {
                            if (nums[i]+nums[j] == target)
                                {
                                    return {i,j};
                                }
                        }
                }
        }
    return {};
}

void printNums(vector<int> v)
{
    for (int &num: v)
        {
            cout << num << " ";
        }
    cout << endl << endl;
}


int main()
{
    cout << "Hello world!" << endl;
    vector<int> indices;
    indices = twoSum({1,2,3,4,5,6,7},7);
    printNums(indices);

    vector<int> test2;
    test2 = twoSum({1,2,3,4,5}, 7);
    printNums(test2);

    vector<int> test3;
    test3 = twoSum({1,2,8,15,9,3}, 12);
    printNums(test3);

    vector<int> testNegative;
    testNegative = twoSum({-1,-2,3,4,5}, -3);
    printNums(testNegative);
    if (-1 + -2 == -3)
        cout << "yes" ;

    return 0;
}
