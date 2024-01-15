#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#include <vector>
#include <algorithm>

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        // We use a large number to initialize the dp array
        int Max = amount + 1;
        std::vector<int> dp(amount + 1, Max);
        dp[0] = 0; // base case: 0 coins are needed for amount 0

        // Build up the dp table
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = std::min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        // If dp[amount] is still Max, then it's not possible to make change
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

















int main()
{
    cout << "Coin Change LeetCode !" << endl;
    vector<int> v = {1,2,5,12};
    int target = 11;

    Solution s1;
    cout << s1.coinChange(v,target) << endl;
    return 0;
}
