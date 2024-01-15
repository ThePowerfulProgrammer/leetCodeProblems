#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices);
};

int Solution::maxProfit(vector<int>& prices)
{
    // 7,1,5,3,6,4
    int buy = prices[0];
    int profit = 0;
    for (int i = 1;i<prices.size();i++)
        {
            if (prices[i] < buy && i != prices.size()-1) // Current value is less than buy price & is not the last element in the vector
            {
                buy = prices[i];
            }
            else if (prices[i] > buy && prices[i] - buy > profit)
                {
                    profit = prices[i] - buy;
                }
        }
    cout << profit << endl;
    return profit;
}

int main()
{
    cout << "maxProfit!" << endl;

    Solution s1;
    vector<int> nums = {7,1,5,3,6,1};
    cout << s1.maxProfit(nums);
    return 0;
}
