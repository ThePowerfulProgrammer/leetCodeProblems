#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



/**
## Bing
A greedy algorithm is an approach for problem-solving where the best or optimal choice is made at each decision point with the hope that these local optimums will lead to a global optimum solution.
Here are some key characteristics of a greedy algorithm:
- It builds up a solution piece by piece, always choosing the next piece that offers the most obvious and immediate benefit.
- It doesn't worry whether the current best result will bring the overall optimal result.
- The algorithm never reverses the earlier decision even if the choice is wrong.
- It works in a top-down approach.
- It picks the path that seems optimal at the moment without regard for the overall optimization of the solution that would be formed.
So, problems where choosing locally optimal also leads to a global solution are the best fit for Greedy algorithms. For example, consider the Fractional Knapsack Problem. The local optimal strategy is to choose the item that has maximum value vs weight ratio. This strategy also leads to a globally optimal solution because we are allowed to take fractions of an item.

*/

class Solution {
public:
    // g is child cookie content size and s is cookie size
    int findContentChildren(vector<int>& g, vector<int>& s)
    {
        if (s.size() == 0 ) {return 0;}
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int cookieCount = 0;

        // Traverse g
        for (int i=0;i<g.size();i++)
            {
                // traverse s
                if (s.size() == 0 )
                    {
                        break;
                    }

                for (int j=0;j<s.size();j++)
                    {
                        if (s[j] >= g[i])
                            {
                                cout << s[j] << " = " << g[i] << endl;
                                cookieCount +=1;
                                if (j != 0)
                                    {
                                        s.erase(s.begin()+j);
                                        break;
                                    }

                                s.erase(s.begin());
                                break;
                            }
                    }
            }

        return cookieCount;

    }
};

// Input: g = [1,2], s = [1,2,3]

int main()
{


    Solution s1;

    vector<int> g = {1,2};
    vector<int> s = {1,2,3};

    cout << s1.findContentChildren(g,s) << endl;
    return 0;
}
