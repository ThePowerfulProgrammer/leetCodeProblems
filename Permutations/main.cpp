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
                return {}; // an empty vector
            }
        else if (nums.size() == 1)
            {
                return { {nums[0]} };
            }
        else if (nums.size() == 2)
            {
              return { {nums[0], nums[1]}, {nums[1], nums[0]} };
            }
        else
            {
                // recursive cases
                // asusume we have  <1,2,3> as nums
                for (int i=0;i<nums.size();i++)
                    {
                        vector<int> currentValue = {nums[i]}; // grab a value and reduce size of next vector
                        vector<int> remainingValues;
                        copy_if(nums.begin(), nums.end(), std::back_inserter(remainingValues),
                                [&currentValue](int j){return j != currentValue[0]; } ); // creates a vector of size n-1 consisting of all values besides nums[i]

                        vector<vector<int>> solutionVectorOne = permute(currentValue); // { {1} }
                        vector<vector<int>> solutionVectorTwo =  permute(remainingValues); // { {2,3}, {3,2} }

                        for (auto subVec: solutionVectorTwo)
                            {
                                subVec.push_back(solutionVectorOne[0][0]); // { {2,3,1}, {3,2,1}  }
                                subSolutionMatrix.push_back(subVec);
                            }

                        solutionMatrix.insert(solutionMatrix.end(), subSolutionMatrix.begin(), subSolutionMatrix.end());
                        subSolutionMatrix.clear();

                    }
            }

        return solutionMatrix;
    }

private:
    vector<vector<int>> subSolutionMatrix = {};
    vector<vector<int>> solutionMatrix;


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

    for (auto v: s1.permute(v4))
        {
            printVector(v);
            cout << "\n";
        }


    return 0;
}
