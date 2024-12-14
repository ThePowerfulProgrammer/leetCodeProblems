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
        return permunateAdd(nums); // vector of vectors
    }

private:
    vector<vector<int>> solutionMatrix;
    vector<int> solutionRow;
    vector<vector<int>> finalMatrix;

    vector<vector<int>> permunateAdd(vector<int> &v)
    {
        // base cases
        if (v.size() == 0)
            {
                return {};

            }
        else if (v.size() == 1)
            {
                return {v};
            }
        else if (v.size() == 2)
            {
                /*
                    permutate({a,b}) = {{a,b}, {b,a}}
                */
                solutionMatrix = {{v[0], v[1]}, {v[1], v[0]} };
                return solutionMatrix;
            }
        else
            {
                // backtrack case
                cout << "backtrack time" << endl;
                for (int i=0;i<v.size();i++)
                    {
                        vector<int> tempVec = {v[i]};
                        vector<int> remainingValues;
                        copy_if(v.begin(), v.end(),std::back_inserter(remainingValues),
                                [&tempVec](int j){return j != tempVec[0]; } ); // {2,3.4}

                        vector<vector<int>> tempMat = permunateAdd(remainingValues); // {{2,3},{3,2}}
                        for (auto vec: tempMat)
                            {
                                vec.push_back(tempVec[0]);

                                finalMatrix.push_back(vec);
                            }

                    }
            }

            solutionMatrix = finalMatrix;
            finalMatrix.clear();
            return solutionMatrix;


    }


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

    printVector(v1);
    cout << endl;
    printVector(v2);
    cout << endl;

    vector<int> v3 = v1;
    vector<int>::iterator it = v2.begin();
    vector<int>::iterator endIt = v2.end();

    v3.insert(std::next(v3.begin(),1), it, endIt);

    printVector(v3);

    cout << endl << endl << endl;

    Solution s1;


    vector<int> v4 = {1,2,3,4};


    for (auto v: s1.permute(v4))
        {
            printVector(v);
            cout << "\n";
        }


    return 0;
}
