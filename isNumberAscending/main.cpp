#include <iostream>

using namespace std;

/**
Problem: Determine if digits in a sentence, appear in ascending order

Description:
A sentence is a list of tokens separated by a single space with no leading or trailing spaces.
Every token is either a positive number consisting of digits 0-9 with no leading zeros, or a word consisting of lowercase English letters.

Input:
String --> sentence
Eg: 1 box has 3 blue 4 red 6 green and 2 yellow marbles

Output:
true || false
Eg: true

Solution Theory:
Read the string                                                                                          (1)
Process the string:                                                                                      (2)
    Find the first apperance of a token digit --> call it x                                              (3)
    Maintain x, until we find the second apperance of a token digit --> call it y                        (4)
    Process (x,y):                                                                                       (5)
        if (y < x) {return false}                                                                        (6)
        else if (y>=x) {set x to y}                                                                      (7)
            modify and repeat steps (3) && (4)                                                           (8)
*/


class Solution {
public:
    bool areNumbersAscending(string s)
    {
       string digits = "0123456789";
       string x = "";
       int y = 0;

       for (int c = 0;c<s.length();c++) // 1 box has 3 blue 4 red 6 green and 12 yellow marbles
        {
            if (digits.find(s[c]) != string::npos)
                {
                    x += s[c];
                }
            else if (digits.find(s[c]) == string::npos && !x.empty())
                {
                    cout << "X: " << stoi(x) << " Y: " << y << endl;
                    if (stoi(x) <= y)
                        {
                            return false; // digits are repeated or digits are descending
                        }
                    y = stoi(x);
                    x = "";
                }
            if (c == s.length()-1 && !x.empty())
                {
                    cout << "X: " << stoi(x) << " Y: " << y << endl;
                    if (stoi(x) <= y)
                        {
                            return false;
                        }
                }
        }

      return true;
    }
};

int main()
{
    cout << "LeetCode is number ascending!" << endl;
    Solution s1;
    cout << s1.areNumbersAscending("1 box has 3 blue 4 red 6 green and 12 yellow marbles") << endl;
    cout << s1.areNumbersAscending("hello world 5 x 5") << endl;
    cout << s1.areNumbersAscending("sunset is at 7 51 pm overnight lows will be in the low 50 and 60 s") << endl;
    return 0;
}
