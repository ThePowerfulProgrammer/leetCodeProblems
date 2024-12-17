#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
    This should be under backtracking

 input: {1,2,3}

 output: {{1,2,3}, {1,3,2}, {2,1,3},{2,3,1}, {3,2,1}, {3,1,2}}

 Method:

 Choose a starting index with a mapped number
    From there repeat until the created vector is of size equivalent to the size of the original vector


 */


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        // base cases
        if (nums.size() == 0)
            {
                return {nums};
            }

        // recursive backtracking call
        vector<int> temp = vector<int>(nums.begin() + 1, nums.end());
        vector<vector<int>> permutations = permute(temp); // will run until we create temp to be {  }

        vector<vector<int>> res;

        for (const auto &p: permutations) // grab indiviual row vectors
            {

                for (int i=0; i<=p.size(); i++)
                    {
                        vector<int> p_copy = p; // create copy of row vector as we intend to alter it
                        p_copy.insert(p_copy.begin() + i, nums[0]);
                        res.push_back(p_copy);
                    }
            }

        return res;

    }

private:


};


void printVector(vector<int> &v)
{
    for (int i: v)
        {
            cout << i << " " ;
        }
}

int main()
{
    cout << "Solve permutations using backtracking!" << endl;

    vector<int> v1 = {1};
    vector<int> v2 = {2,3};

    //printVector(v1);
    cout << endl;
    //printVector(v2);
    cout << endl;

    vector<int> v3 = v1;
    vector<int>::iterator it = v2.begin();
    vector<int>::iterator endIt = v2.end();

    v3.insert(std::next(v3.begin(),1), it, endIt);

 //    printVector(v3);

    cout << endl << endl << endl;

    Solution s1;

    vector<int> v4 = {1,2,3,4}; // permutations should result in a matrix of size 4! = 4 * 3 * 2 * 1 = 24

    for (auto v: s1.permute(v3))
        {
            printVector(v);
            cout << "\n";
        }


    return 0;
}
