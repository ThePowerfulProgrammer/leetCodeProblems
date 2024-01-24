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


int surfaceArea(vector<vector<int>>& grid)
{
    /** 1) I need a var to store the total surface area */
    int totalSurfaceArea = 0;

    /** 2) I need to traverse the grid and evaluate every indivual entry */
    /** To evaluate means to consinder every vertical and horizontal neighbour AKA adjacent entries */
    /** We take the ith value*6 to find the potential total surface area */
    /** A successful match is one that is >= value as the considerd entry. Minus all accepted */
    /** Prior to that we take the ith value sum and minus (i-1)*2 then we repeat the prior steps until our value is 0 **/

    for (int i=0;i<grid.size();i++)
        {
            for (int j=0;j<grid[i].size();j++)
                {
                    if (grid[i][j] != 0 )
                    {
                        int sum = grid[i][j]*6; // Potential total surface area
                        sum -= (grid[i][j]-1)*2; // The implicit sharing of bottom and top faces
                        int value = grid[i][j];

                        while (value != 0)
                            {
                                if (j-1 > -1 && grid[i][j-1] != 0 && grid[i][j-1] >= value)
                                    {
                                        //cout << "left/right neightbour" << endl;
                                        sum -=1;
                                    }
                                if (j + 1<grid[i].size() && grid[i][j+1] != 0 && grid[i][j+1] >= value)
                                    {
                                        sum -=1;
                                    }

                                if (i-1 > -1 && grid[i-1][j] != 0 && grid[i-1][j] >= value)
                                    {
                                        //cout << "vertical neightbours" << endl;
                                        sum -=1;
                                    }
                                if (i+1 < grid.size() && grid[i+1][j] != 0  && grid[i+1][j] >= value)
                                    {
                                        sum -=1;
                                    }
                                value -= 1;
                            }
                        totalSurfaceArea += sum;
                    }
                }
        }
    return totalSurfaceArea;

}


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
    cout << endl << endl;
    cout << surfaceArea(grid) << endl;
    return 0;
}
