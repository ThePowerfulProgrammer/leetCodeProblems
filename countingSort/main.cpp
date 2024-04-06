#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;



class Solution {

public:
    vector<int> sortedArray(vector<int> &unsorted)
    {
        // step 1 -> Count number of occurences

        cout << min(unsorted) << endl;
        cout << max(unsorted) << endl;
        return {};
    }

private:
    int min(vector<int> &unsorted)
    {
        int smallest = unsorted[0];

        vector<int>::iterator i;

        for (i = unsorted.begin(); i != unsorted.end(); ++i)
            {
                if (*i < smallest)
                    {
                        smallest = *i;
                    }
            }


        return smallest;
    }

    int max(vector<int> &unsorted)
    {
        int largest = unsorted[0];
        vector<int>::iterator i;

        for (i = unsorted.begin();i != unsorted.end(); ++i)
            {
                if (*i > largest)
                    {
                        largest = *i;
                    }
            }

        return largest;
    }

};

int main()
{
    cout << "Implement Counting Sort!" << endl;
    vector<int> nums = {1,0,1,3,1,3,1};

    Solution s1;
    s1.sortedArray(nums);
    return 0;
}
