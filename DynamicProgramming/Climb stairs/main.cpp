#include <iostream>
#include <ctime>
#include <map>

using namespace std;

/*
You are given an integer n representing the number of steps to reach the top of a staircase. You can climb with either 1 or 2 steps at a time.

Return the number of distinct ways to climb to the top of the staircase.

Do I see A counting problem?

Assume we are given 1 step:
    we return 1
    1 = 1

Assume we are given 2 steps:
    we return 2
    1 + 1 = 2
    2 = 2


*/

class Solution {
public:
    int climbStairs(int n)
    {
        if (n == 1)
            {
                return 1; // only one way to climb the stair case
            }
        else if (n == 2)
            {
                return 2; // 2 ways to climb the staircase
            }

    //  return climbStairs(3) + climbStairs(2) == [climbStairs(2) + climbStairs(1)] + 2 = [2 + 1] + 2 = 5
        return climbStairs(n - 1) + climbStairs(n - 2);
    }

private:

};


int main()
{
    time_t timeStampCurrent;
    time(&timeStampCurrent);
    cout << "Current Time: " <<ctime(&timeStampCurrent) << "\n";
    cout << "Climbing stairs while DP!" << endl;

    Solution s1;
    cout << s1.climbStairs(1) << endl;
    cout << s1.climbStairs(2) << endl;
    cout << s1.climbStairs(3) << endl;
    cout << s1.climbStairs(4) << endl;
    cout << s1.climbStairs(5) << endl;
    cout << s1.climbStairs(6) << endl;

    cout <<

    return 0;
}
