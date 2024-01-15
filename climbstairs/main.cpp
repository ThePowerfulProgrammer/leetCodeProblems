#include <iostream>
#include <unordered_map>
using namespace std;


/** CHECK WHITEBOARD climbStairs */
class Solution {
public:
    int climbStairs(int n)
    {
        if (n == 1)
            {
                return 1;
            }
        else if (n == 2)
            {
                return 2;
            }
        else
            {
                if (memo.find(n) != memo.end())
                    {
                        return memo[n];
                    }
                memo[n] = climbStairs(n-1) + climbStairs(n-2);
                return memo[n];
            }
    }
private:
    unordered_map<int,int> memo; // used to store k:v pairs
};

int main()
{
    cout << "Climb stairs Recursion + DP!" << endl;
    Solution s1;

    cout << s1.climbStairs(45) << endl;

    return 0;
}
