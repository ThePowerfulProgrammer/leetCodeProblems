#include <iostream>
#include <vector>

using namespace std;

/**
    prices = [10,1,5,6,7,1]

    How would I maximise profit?
    I buy on day i = PP
    I look forward from i and consider a window of size: prices.size() - i
        I then PP - currentPrice:
            if greater then maxProfit:
                maxProfit is set to new profit

*/

class Solution
{
    public:

        int maxProfit(vector<int>& prices)
        {
            int maxProfit = 0;

            for (int i=0;i<prices.size();i++)
                {
                    int purchasePrice = prices[i];
                    // consider a window of size: prices.size() - 1
                    for (int j=i+1;j<prices.size();j++)
                        {
                            if (prices[j] - purchasePrice > maxProfit)
                                {
                                    maxProfit = prices[j] - purchasePrice;
                                }
                        }
                }

            return maxProfit;
        }
};

int main()
{
    cout << "Time to buy Shitcoins!" << endl;

    Solution s1;
    vector<int> nums = {10,1,5,6,7,1};
    vector<int> nums1 = {10,8,7,5,2};

    cout << s1.maxProfit(nums) << endl;
    cout << s1.maxProfit(nums1) << endl;
    return 0;
}
