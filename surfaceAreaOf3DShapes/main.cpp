#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid)
    {

    int totalUnits = 0;
    for (int i=0;i<grid.size();i++)
        {
            for (int j=0;j<grid[i].size();j++)
                {
                    if (grid[i][j] > 0 )
                        {
                            int sum = grid[i][j] * 6;
                            sum -= (grid[i][j]-1)*2;

                            if (j-1 > -1 && grid[i][j-1] != 0)
                                {
                                    //cout << "left/right neightbour" << endl;
                                    sum -=1;
                                }
                            if (j + 1<grid[i].size() && grid[i][j+1] != 0 )
                                {
                                    sum -=1;
                                }

                            if (i-1 > -1 && grid[i-1][j] != 0 )
                                {
                                    //cout << "vertical neightbours" << endl;
                                    sum -=1;
                                }
                            if (i+1 < grid.size() && grid[i+1][j] != 0  )
                                {
                                    sum -=1;
                                }
                            sum -= (grid[i][j]-1);
                            totalUnits += sum;
                        }
                }
        }

        return totalUnits;
    }
};

int main()
{
    cout << "Surface area of a 3D shape!" << endl;
    vector<vector<int>> grid = {{1,2},{3,4}};

    // output the vector
    int totalUnits = 0;
    for (int i=0;i<grid.size();i++)
        {
            for (int j=0;j<grid[i].size();j++)
                {
                    int sum = grid[i][j] * 6;
                    sum -= (grid[i][j]-1)*2;

                    if (j-1 > -1)
                        {
                            //cout << "left/right neightbour" << endl;
                            sum -=1;
                        }
                    if (j + 1<grid[i].size())
                        {
                            sum -=1;
                        }

                    if (i-1 > -1 )
                        {
                            //cout << "vertical neightbours" << endl;
                            sum -=1;
                        }
                    if (i+1 < grid.size())
                        {
                            sum -=1;
                        }
                    sum -= (grid[i][j]-1);
                    totalUnits += sum;
                }
            cout << endl;

        }
    cout << totalUnits << endl;

    Solution s1;
    cout << s1.surfaceArea(grid) << endl;
    return 0;
}
