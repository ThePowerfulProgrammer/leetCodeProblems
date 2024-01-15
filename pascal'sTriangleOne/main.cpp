#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        // nuwRows is found
        if (map.find(numRows) != map.end())
            {
                return v;
            }

        // v = {{1},{1,1}, {1,2,1} }

        if (numRows == 1)
            {
                map[1] = {1};
                v.push_back(map[1]);
            }
        else if (numRows == 2)
            {
                generate(numRows - 1);
                map[2] = {1,1};
                v.push_back(map[2]);
            }
        else
            {
                generate(numRows-1);
                vector<int> row(numRows,0); // {0,0,0}

                row[0] = 1;
                row[row.size()-1] = 1;

                for (int i=1;i<row.size()-1;i++)
                    {
                        // row[1] = v[1][1] + v[1][0] = 1 + 1 = 2
                        row[i] = v[numRows-2][i] + v[numRows-2][i-1];
                    }

                //cout << "Out of loop" << endl;
                //cout << " 2? " << row[1] << endl;

                map[numRows] = row;
                v.push_back(map[numRows]); // { {1}, {1,1} } =  { {1}, {1,1}, {1,2,1} }

            }
        return v;

    }
private:
    unordered_map<int,vector<int>> map;
    vector<vector<int>> v;
};


void getMatrixEntries(vector<vector<int>> m)
{
    for (auto& row: m)
        {
            for (int i=0;i<row.size();i++)
                {
                    cout << row[i] << " ";
                }
            cout << endl;
        }
}




int main()
{
    cout << "Pascal's Triangle I!" << endl;
    vector<vector<int>> v;

    Solution s1;

    getMatrixEntries(s1.generate(10));

    return 0;
}
