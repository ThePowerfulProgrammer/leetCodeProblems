#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
You are given an integer array nums. You need to create a 2D array from nums satisfying the following conditions:

The 2D array should contain only the elements of the array nums.
Each row in the 2D array contains distinct integers.
The number of rows in the 2D array should be minimal.
Return the resulting array. If there are multiple answers, return any of them.

Note that the 2D array can have a different number of elements on each row.

*/


bool vectorFind(vector<int> v, int i)
{
    // find i in v
    for (int num: v)
        {
            if (num == i)
                {
                    return true;
                }
        }
    return false;
}

class Solution {
public:

    /** \brief
        Create a matrix such that rows only contain unique values from nums.
        First create a dict using nums.
        Maintain a highest count of Values.
        Start a for loop from 0 to highest value.
            the for loop will create an empty vector.
            check the vector for the values from dict.
            if it not(exists) --> Add it to the vector and reduce the value in dict
            Add the newly populated vector to the matrix.
            Repeat this process via the for loop.

        step 1: Create dict
        Step 2: Populate dict, maintain highest value
     *
     * \param
        vector

     * \return
        vector<vector> matrix
     *
     */

    void populateDict(vector<int> nums, unordered_map<int,int> &dict)
    {
        for (const int i: nums)
            {
                if (dict.find(i) != dict.end())
                    {
                        int value = dict[i] + 1;
                        dict[i] = value;
                        if (value > highest)
                            {
                                highest = value;
                            }
                    }
                else
                    {
                        dict[i] = 1;
                        if (dict[i] >= highest)
                            {
                                highest = dict[i];
                            }
                    }
            }
    }

    void createMatrix(vector<vector<int>> &matrix)
    {
        for (int rows = 0; rows<highest;rows++)
            {
                vector<int> row = {};
                for (const auto& pair:dict)
                    {
                        if (!vectorFind(row,pair.first) && pair.second > 0)
                            {
                                row.push_back(pair.first);
                                int reducedVal =  pair.second - 1;
                                dict[pair.first] = reducedVal;
                            }
                    }

                matrix.push_back(row);
            }
    }
    vector<vector<int>> findMatrix(vector<int>& nums)
    {
        populateDict(nums,dict);
        createMatrix(matrix);
        return matrix;
    }

private:
    int highest = 0; // highest val in dict
    unordered_map<int,int> dict;
    vector<vector<int>> matrix;
};


void outputMatrix(vector<vector<int>> matrix)
{
    for (const auto &row: matrix)
        {
            for (int i: row)
                {
                    cout << i << " ";
                }
            cout << endl;
        }
}

int main()
{
    cout << "Creating a matrix!" << endl;

    unordered_map<int,int> dict;
    vector<int> nums = {2,3,1};

    // I also should keep track of the largest key:value pairs
    int highest = 0;
    for (const int i: nums)
        {
            if (dict.find(i) != dict.end())
                {
                    cout << "Already in dict, therefore increment" << endl;
                    int value = dict[i] + 1;
                    dict[i] = value;
                    cout << "Value: "<< value << " Highest: " << highest << endl;
                    if (value > highest)
                        {
                            highest = value;
                        }
                }
            else
                {
                    cout << "I have never seen this number in my entire life" << endl;
                    dict[i] = 1;
                    if (dict[i] >= highest)
                        {
                            highest = dict[i];
                        }
                }
        }


    for(const auto& pair:dict)
        {
            cout << pair.first << ":" << pair.second << endl;
        }

    /**<
    What I want to do is, I want to use the values in the assoicated keys and cross check their
    existence in a vector, if it is in the vector, I do nothing else I add it to the vector and I remove one instance from the dict[keys]
    */

    cout << "we need to create " << highest << " vectors" << endl;
    vector<int> row1 = {};

    vector<vector<int>> matrix;

    for (int rows = 0; rows<highest;rows++)
        {
            vector<int> row = {};
            for (const auto& pair:dict)
                {
                    if (!vectorFind(row,pair.first) && pair.second > 0)
                        {
                            row.push_back(pair.first);
                            int reducedVal =  pair.second - 1;
                            dict[pair.first] = reducedVal;
                        }
                }

            matrix.push_back(row);
        }

    for (const auto& pair: dict)
        {
            cout << "Checking this value: " << pair.second << endl;
            if (!vectorFind(row1, pair.first) && pair.second > 0)
                {
                  row1.push_back(pair.first);
                  int reducedVal = pair.second - 1;
                  dict[pair.first] = reducedVal;
                }
        }

    for (int i: row1)
        {
            cout << i << " " ;
        }
    cout << endl;

    for(const auto& pair:dict)
        {
            cout << pair.first << ":" << pair.second << endl;
        }

    cout << endl << endl << endl << endl;

    cout << "Output matrix: " << endl;
    outputMatrix(matrix);

    cout << endl << endl << endl << endl;

    cout << endl << endl << endl << endl;

    Solution s1;

    outputMatrix(s1.findMatrix(nums));
    return 0;
}
