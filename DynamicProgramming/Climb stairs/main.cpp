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
    Solution()
    {
        costToClimbStairMaps[0] = 0;
        costToClimbStairMaps[1] = 1;
        costToClimbStairMaps[2] = 2;
    }

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

    int climbStairsMemoisationApproach(int n)
    {

        if (costToClimbStairMaps.find(n) != costToClimbStairMaps.end())
            {
                return costToClimbStairMaps[n];
            }
        else
            {
                costToClimbStairMaps[n] = costToClimbStairMaps[n - 2] + costToClimbStairMaps[n - 1];
                return costToClimbStairMaps[n];
            }
    }
private:
    map<long, long> costToClimbStairMaps;


};


int main()
{
    cout << "Climbing stairs while DP!" << endl;

    // the dp approach
    Solution s;
    for (int i=1;i<45;i++)
        {
            cout << "n = " << i << " " << s.climbStairsMemoisationApproach(i) << endl;
        }
    // execution time : 0.076 s  for n == 30
    // execution time : 0.099 s for n == 45

/*
    Solution s1;

    for (int i=1;i<50;i++)
        {
            cout << s1.climbStairs(i) << endl;
        }*/
    // execution time : 0.094 s for n == 30
    // execution time : for n == 50 caused the program to run slow

    return 0;
}
