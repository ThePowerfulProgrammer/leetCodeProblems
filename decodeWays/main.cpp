#include <iostream>
#include <unordered_map>
using namespace std;


/**
    If I am using recursion I need a base case(s).

    Say I am given s = 12
    I should return 2 because s = 12 = AB = (1)(2) = L = (12)

    What if I were to consider S as a number and consider the number of ways I can deconstruct S into?
    S = 12
    S = 1 + 2 = 12
    S = 12

    Can I use Tabulation
    11

*/

class Solution {
public:
    int numDecodings(string s)
    {

    }

private:
    unordered_map<char,int> map = {
        {'A':1},
        {'B':2},
        {'C':3},
        {'D':4},
        {'E':5},
        {'F':6},
        {'G':7},
        {'H':8},
        {'I':9},
        {'J':10},
        {'K':11},
        {'L':12},
        {'M':13},
        {'N':14},
        {'O':15},
        {'P':16},
        {'Q':17},
        {'R':18},
        {'S':19},
        {'T':20},
        {'U':21},
        {'V':22},
        {'W':23},
        {'X':24},
        {'Y':25},
        {'Z':26}
    }

}

int main()
{
    cout << "Decode string using Recursion and DP!" << endl;

    for (int i=4;i<27;i++)
        {
            cout << ":" << i << "}," << endl;
        }
    return 0;
}
