#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>


using namespace std;

/*
Given 2 integers, n and k, return all possible combinations of k numbers chosen from the range [1,n].

Input: n = 4, k = 2. Therefore [1,4]
Output: [[1,2], [1,3],[1,4], [2,3], [2,4], [3,4]]


So we create a list of lists consisting of objects of size k.
Where the elements [x,y] are elements in [1,n]

Cannot have [x,x]


if k == 0 || n == 0:
    return []
if n == 1, then k does not matter:
    return [[1]]
if k == 1, then n is the upper limit:
    say n == 4:
        return [ [1], [2], [3], [4] ]

say k = 2, therefore [1,n] and n > k

for j in range(k):
    for i in range(n):
        if (i != j):
            create [j+1,i+1] == [1,2], [1,3], [1,n]
            append the above to a larger table

*/
class Solution
{
public:

    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> table = {};

        if ( k == 0 || n == 0)
            {
                return table;
            }
        if (n == 1)
            {
                vector<int> v = {1};
                table.push_back(v);
                return table;
            }

        if (k==1)
            {
                for (int i=0; i<n;i++)
                    {
                        vector<int> v(1,i+1);
                        table.push_back(v);
                    }
                return table;

            }

        if (k > 1)
            {
                for (int j=0;j<k+1;j++)
                    {
                        for (int i=0;i<n;i++)
                            {
                                if (i != j && (searchTable(table,j+1,i+1)) && (searchTable(table,i+1,j+1))    )
                                    {
                                        vector<int> row = {j+1, i+1};
                                        table.push_back(row);
                                    }
                            }
                    }
                return table;
            }


        return table;

    }


private:
    bool searchTable(vector<vector<int>> t, int x, int y)
    {
        for (int i=0;i<t.size(); i++)
            {
                if ( (t[i][0] == x && t[i][1] == y) || (t[i][0] == y && t[i][1] == x) )
                    {
                        return false;
                    }
            }
        return true;
    }
};


void printTable(vector<vector<int>> t)
{
    for (int r = 0; r<t.size(); r++)
    {
        for (int c =0;c<t[0].size(); c++)
        {
            cout << t[r][c] << " ";
        }
        cout << endl;
    }

}

int main()
{
    Solution s1;
    cout << "Combinations(2,2)!: " << endl;
    for (auto v: s1.combine(4,3))
        {
            for (auto i: v)
                {
                     cout << i << " ";
                }
             cout << endl;
        }


    cout << endl << endl << endl;

    /*
    vector<vector<int>> table= {
        {2,1},
        {3,1}
    };

    printTable(table);

    for (int i=0;i<table.size(); i++)
    {
        if ((table[i][0] == 1 && table[i][1] == 2 ) || (table[i][0] == 2 && table[i][1] == 1))
        {
            cout << "found \n";
        }
    }*/


    return 0;
}













