#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/**
Given two binary strings a and b, return their sum as a binary string.

Example 1:

Input: a = "11", b = "1"
Output: "100"

Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
*/

class Solution {
    public:
        // "11","1"
        string addBinary(string a, string b) {
            string result = "";
            int carry = 0;
            int i = a.length() - 1;
            int j = b.length() - 1;
            while (i >= 0 || j >= 0 || carry) {
                int sum = carry;
                if (i >= 0) {
                    sum += a[i] - '0';
                    i--;
                }
                if (j >= 0) {
                    sum += b[j] - '0';
                    j--;
                }
                carry = sum / 2;
                result += to_string(sum % 2);
            }
            reverse(result.begin(), result.end());
            return result;
    }
};

int main()
{
    Solution s1;
    cout << s1.addBinary("11","1");

    return 0;
}
