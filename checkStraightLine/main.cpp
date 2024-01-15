#include <iostream>
#include <vector>

using namespace std;

bool checkStraightLine(vector<vector<int>>& coordinates) {
    // Need to check if vertical line
    double x = coordinates[0][0];
    int xCount = 0;
    for (int i=0;i<coordinates.size();i++)
        {
            if (coordinates[i][0] == x)
                {
                    xCount +=1;
                }
        }
    if (xCount == coordinates.size())
        {
            return true;
        }

    double y = coordinates[0][1];
    int yCount = 0;
    for (int i=0;i<coordinates.size();i++)
        {
            if (coordinates[i][1] == y)
                {
                    yCount +=1;
                }
        }
    if (yCount == coordinates.size())
        {
            return true;
        }

    // initial gradient calculation
    double numerator = coordinates[1][1] - coordinates[0][1];
    double denominator = coordinates[1][0] - coordinates[0][0];

    double gradient = numerator/denominator;

    for (int i=0;i<coordinates.size()-1;i++)
        {

            double n = coordinates[i+1][1] - coordinates[i][1];
            double d = coordinates[i+1][0] - coordinates[i][0];
            if (d == 0)
                {
                    return false;
                }

            double g = n/d;
            if (abs(g - gradient) > 1e-9)
                {
                    return false;
                }
        }
    return true;
}

int main()
{
    vector<vector<int>> coordinates = {{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}};


//    for (int i=0;i<coordinates.size();i++)
//        {
//            cout << coordinates[i][0] << " x " << endl;
//            cout << coordinates[i][1] << " y " << endl;
//            for (int j=0;j<coordinates[i].size();j++)
//                {
//                    if (coordinates[i+1][j] - coordinates[i][j] == 0) { cout << "We got a problem over here" << endl;}
//                }
//            cout << endl;
//        }

    bool test = checkStraightLine(coordinates);
    cout << test << endl;
    vector<vector<int>> verticalLine = {{0,0},{0,1},{0,-1}};
    vector<vector<int>> horizontalLine = {{0,0},{1,0},{-1,0}};

    cout << checkStraightLine(verticalLine) << endl;
    cout << checkStraightLine(horizontalLine) << endl;

    vector<vector<int>> testCase {{1,2},{2,3},{3,5}};
    cout << checkStraightLine(testCase) << endl;


    return 0;
}
