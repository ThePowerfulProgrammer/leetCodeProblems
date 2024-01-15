#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

/**
Example run:
Read 1, do nothing
Read 8, 8 is no our dominate line.
No need to back track and calculate area.
Read 6, calulate Area = 1x6 = 6.
Read 2, A = 2 x 2 = 4.
Read 5, A = 3 x 5 = 15.
Read 4, A = 4 x 4 = 16
Read 8, A = 5 x 8 = 40
Read 3, A = 6 x 3 = 18
Read 7, A = 7 x 7 = 49
Return largest: 49

Unique Cases? :
vector empty: Return 0
Vector consists of 2 elements: A = Smallest Element x 1


Potentiation:
Sort vector beforehand? How would this change the implementation of the function.
We will potentially switch the dominate line on every advancement -> We also have to calculate area from the left.

*/
using namespace std;

/*
What we need to focus on  is using 2 lines to create a Rectangle.
The shorter line is the length and the distance between them is the Breadth.

A = L x b

When do we switch the dominate area line?

IF we come accross a line that is greater in height and is not the last element.
*/

class Solution {
public:
    int maxArea(vector<int>& height)
    {
        if (height.size() == 2) // redundant
            {
                int h = *min_element(height.begin(),height.end());
                return 1*h;
            }

        int area = 0;

        // iterate over all the values of height
        for (int i=0;i<height.size();i++)
            {
                if (height[i] != 0)
                    {
                        for (int j=i+1;j<height.size();j++)
                            {
                                int minHeight = (height[i]<=height[j]) ? height[i]:height[j];
                                cout << area << endl;
                                area = (minHeight*(j-i) > area) ? minHeight*(j-i):area;
                            }
                    }
            }

       return area;
    }
};


int maxArea(vector<int> heights)
{
    int area = 0;
    int n = 0;
    int indexOne = heights[n];
    int indexTwo = heights[n+1];

    for (int i=heights.size()-1;i>0;i--)
        {

        }
}





















int main()
{
    cout << "Container with the most water!" << endl;

    vector<int> lines = {1,8,6,2,5,4,8,3,7};
    vector<int> heights = {1,2,3,4,5,6,7,8,8};

    Solution s1;
    cout << s1.maxArea(lines) << endl;
    return 0;
}
