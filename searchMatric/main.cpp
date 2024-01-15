#include <iostream>
#include <vector>
using namespace std;





bool binSearch(vector<int> &array, int target)
{
    int a = 0;
    int b = array.size() - 1;

    while (a <= b)
    {
        int mid = a + (b - a) / 2;
        //cout << mid << endl;
        if (array[mid] == target)
        {
            return true;
        }
        if (array[mid] < target) // Compare with target
        {
            a = mid + 1;
        }
        else
        {
            b = mid - 1;
        }
    }
    return false;
}

void outputMatrix(vector<vector<int>> &matrix)
{

    // Displaying vector elements using begin() and end()
    cout << "The vector elements are : " << endl;
    for (auto& row: matrix)
        {
            for (int c = 0;c<row.size();c++)
                {
                    cout << row[c]<< endl;
                }
        }

}



class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        for (auto& v:matrix)
            {
                cout << v.front() << " <= " << target << " <= " << v.back() << endl;
                if ( (v.front() <= target) && (v.back() >= target ) )
                    {
                        cout << "binsearch" << endl;

                            if (binSearch(v,target) == true)
                                {
                                    return true;
                                }
                    }

            }
        return false;

    }
};


int main()
{
    cout << "Search Matrix!" << endl;
    vector<vector<int>> matrix = { {1,3,5,7},{10,11,16,20},{23,30,34,60}};

    Solution s1;
    cout << s1.searchMatrix(matrix,3) << endl;

    return 0;
}
