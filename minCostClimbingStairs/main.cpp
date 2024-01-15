#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
Problem: You are given an integer array cost where cost[i] is the cost of ith step on a staircase.
Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

Description:

Problem Analysis:
        Understand the problem: What is the actual problem? -> Given an array, where the indiviual elements of the array represent a cost.
        You are to determine the lowest total cost out of the array.
        Where the total cost represents the summed indiviual cost of your best path out of the array.

        Devise a plan: What plan of attack will result in our victory? Do we need to break the problem into smaller sub-problems and solve each?
        --> Yes.
        What is the psuedoCode algorithm?
            [10,15,20, 5]
indices       0, 1, 2, 3

            Read in the array
            Process the array

            Create 2 paths, pathA for index 0 and pathB for index 1
            First check (Easy exit):
                from each path jump 1 index ahead, check if new index is > length of array from either path:
                    if so:
                        return cost associated with that path.

            Second check (Easy exit):
                from each path jump 2 indices ahead, check if new index is > length of array from either path:
                    if so:
                        return cost associated with that path.

            Third check (determine next path):
                from each path do the following:
                    sum and process pathA, 1 index away and 2 indices away
                    sum and process pathB, 1 index away and 2 indices away

                    if costpathA < costpathB:
                        use pathA
                    else:
                        use pathB



        Carry out the plan: Implement your plan by writing code to solve the problem. Make sure to test your code with different inputs to ensure that it works correctly.
        For this we will write a function


        Look back: After you have implemented your solution, take some time to look back and reflect on your solution. Did it work as expected?


Input:
    vector<int> &cost

Output:
    int: cost


Solution Theory:
    Code solution
*/

bool areAllElementsEqual(const std::vector<int>& vec)
{
    return std::equal(vec.begin() + 1, vec.end(), vec.begin());
}

class Solution {
public:
    // {10,15,20,5} example array
    //   0,1,2,3    indices
    int minCostClimbingStairs(vector<int>& cost)
    {

        // [0,1,2,2]
        int cheapestPath = 0;
        int i = 0;

        // 0,1,2,2


        while (i<cost.size()-2)
            {
                // step 1
                if (i == 0)
                    {
                        if (i+1 > cost.size() || i+2 >= cost.size())
                            {
                                cheapestPath += cost[i];
                                return cheapestPath;
                            }

                        else if (i+3 >= cost.size())
                            {
                                cheapestPath += cost[i+1];
                                return cheapestPath;
                            }
                        else
                            {
                                // Determine start index
                                //i = (cost[i] < cost[i+1]) ? i:i+1;
                                //i = (cost[i+1] == cost[i]) ? i+1:i;
                                if (cost[i]<cost[i+1])
                                    {
                                        i = i;
                                    }
                                else if (cost[i] >= cost[i+1])
                                    {
                                        i = i+1;
                                    }

                                cout << "pre I: " << i << endl;
                                cheapestPath += cost[i];
                            }
                    }
                // continue adding costs
                // [0,1,2,2]
                // [1,100,1,1,1,100,1,1,100,1]


                if (cost[i+1]<cost[i+2] )
                    {
                        cheapestPath += cost[i+1];
                        i = i+1;
                        cout << "current i: " << i << endl;
                    }
                else
                    {
                        cheapestPath += cost[i+2];
                        i = i+2;
                        cout << "current i: " << i << endl;
                    }

                if (i >= cost.size()-1)
                    {
                        return cheapestPath;
                    }

            }



        return cheapestPath;
    }
};





int main()
{
    cout << "Total cost!" << endl;
    vector<int> testCase1 = {10,15,20};
    vector<int> testCase2 = {1,100,1,1,1,100,1,1,100,1};
    vector<int> testCase3 = {0,1,2,2};

    Solution s1;
    cout << s1.minCostClimbingStairs(testCase1) << endl;
    cout << s1.minCostClimbingStairs(testCase2) << endl;
    cout << s1.minCostClimbingStairs(testCase3) << endl;

    return 0;
}
