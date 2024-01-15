#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {
        // {9,9,9} -> {1,0,0,0}
        // {1,2,3} -> {1,2,3,4}
        // {1,2,9} -> {1,3,0}


        // base case
        for (int i = digits.size()-1;i>-1;i--)
            {
                // best case
                if (digits[i]+1 < 10)
                    {
                        digits[i] = digits[i]+1;
                        return digits;
                    }
                else if (digits[i]+1>9 && i==0)
                    {
                        digits[0] = 0;
                        digits.insert(digits.begin(),1);
                        return digits;
                    }
                else if (digits[i]+1 > 9)// worse case
                    {
                        digits[i] = 0;
                    }

            }

            return digits;
    }
};

int main()
{
    cout << "PLUS ONE!" << endl;
    vector<int> value = {9};
    Solution s1;
    vector<int> incremented;
    incremented = s1.plusOne(value);
    for (int i=0;i<incremented.size();i++)
        {
            cout << incremented[i] << " ";
        }


    return 0;
}
