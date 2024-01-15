#include <iostream>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int fib(int n)
    {
        if (memo.find(n) != memo.end())
            {
                return memo[n];
            }
        if (n == 0)
            {
                return 0;
            }
        if (n == 1)
            {
                return 1;
            }
        memo[n] = fib(n-1) + fib(n-2);
        return memo[n];
    }

private:
    unordered_map<int,int> memo;
};
int main()
{
    cout << "FIB + Recursion + Memoisation!" << endl;
    Solution s1;
    cout << s1.fib(30) << endl;
    return 0;
}
