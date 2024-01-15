#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

/**
Example 1:

Input: num = 3
Output: "III"
Explanation: 3 is represented as 3 ones.
Example 2:

Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 3:

Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.


*/

// convert number to its place value
vector<int>  toPlaceValue(int num)
{
    string numString = to_string(num);
    int length = numString.size() - 1;
    vector<int> values;

    for (int i=0;i<numString.size();i++)
        {
            int value = (numString[i] - '0') * std::pow(10,length);
            values.push_back(value);
            length -= 1;
        }

    return values;

}

// convert array of place value to RN equivalent
vector<int> toRomanEquivalent(vector<int> values) // convert value to 1 of Roman equivalent
{
    vector<int> v = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000}; // Roman values
    vector<string> s = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};

    vector<int> RE;

    for (int i:values)
        {
            if (std::find(v.begin(), v.end(), i) != v.end())
                {
                    //cout << i << " Appears as a RN" << endl;
                    RE.push_back(i);
                }
            else
                {
                    int index = v.size() - 1;
                    while (i != 0) // end condition
                        {
                            if (v[index] < i)
                                {
                                    //cout << i << " Before subtraction" << endl;
                                    i -= v[index];
                                    //cout << i << " After subtraction" << endl;
                                    RE.push_back(v[index]);
                                }
                            else if (v[index] == i)
                                {
                                    RE.push_back(v[index]);
                                    //cout << i << " Before subtraction" << endl;
                                    i -= v[index];
                                    //cout << i << " After subtraction" << endl;
                                }
                            else
                                {
                                    index -=1;
                                }
                        }
                }
        }
    return RE;
}

class Solution {
public:
    string intToRoman(int num)
    {
        // Array's of Roman Characters and Associated integer values
        vector<int> v = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000}; // Roman values
        vector<string> s = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"}; // Roman symbols

        vector<int> values = toRomanEquivalent(toPlaceValue(num)); // values we will be using
        string solution = "";

        for (int i:values)
            {
                auto it = std::find(v.begin(), v.end(), i);

                if (it != v.end())
                {
                    int index = std::distance(v.begin(), it);
                    //cout << i << " is in RN at index " << index << " With s: " << s[index] << endl;
                    solution += s[index];
                }
            }
        return solution;

    }
};

int main()
{


    /*for (int i:toRomanEquivalent(toPlaceValue(321)) )
        {
            cout << i << " ";
        }*/

    Solution s1;
    cout << s1.intToRoman(3999);
    // MMMCMXCIX
    return 0;
}
