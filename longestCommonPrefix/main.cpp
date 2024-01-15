#include <iostream>
#include <vector>
#include <string>

using namespace std;


// iteration 0
// Given a vector containing strings, determine if there is a common prefix(series of common chars) amongst all strings
// if so return the longest common prefix
// [flower,flow,flight]
/*
Need to determine if the ith string at the jth posistion contains the current character
If this is true for all strings then add char to prefix
*/
// {"flower", "fly", "flown"}

string longestCommonPrefix(vector<string> & strs)
{
    string prefix = "";
    int pos = 0;
    char currentChar = strs[0][pos];

    // if characterCount == strs.size() iff all words contain currentChar
    int characterCount = 0;

    while (pos < strs[0].length()) {
        char currentChar = strs[0][pos];
        int characterCount = 0;

        for (auto &word: strs)
            {
                if (pos >= word.length() || word[pos] != currentChar)
                    {
                        return prefix;
                    }
                if (word[pos] ==  currentChar)
                    {
                        characterCount +=1;
                    }
            }
        if (characterCount == strs.size())
            {
                prefix += currentChar;
            }

        pos += 1;

    }
    return prefix;
}

int main()
{
    vector<string> vectorOne= {"flower", "fly", "flown"};
    cout << longestCommonPrefix(vectorOne) << endl << endl;



    vector<string> vectorTwo = {"dog","racecar","car"};
    cout << longestCommonPrefix(vectorTwo) << endl;

    return 0;
}
