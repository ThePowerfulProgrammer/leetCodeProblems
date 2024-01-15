#include <iostream>

using namespace std;

/*
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack,
or -1 if needle is not part of haystack.
*/


int strStr(string haystack, string needle)
{
    int letterMatches = 0; // used as a counter to determine if needle is a substring of haystack

    for (int letter = 0;letter<haystack.size();letter++)
        {
            int copyLetter = letter;

            for (char c: needle)
                {
                    if (haystack[copyLetter] == c)
                        {
                            letterMatches +=1;
                            copyLetter +=1;
                        }
                    else
                        {
                            break;
                        }
                }

            if (letterMatches == needle.size())
                {
                    return letter; // index of the match
                }

            letterMatches = 0;
        }
    return -1;
}



int main()
{
    cout << strStr("needle", "need") << endl; // PC: return 0
    cout << strStr("neeleneed","need") << endl; // PC: return 5
    cout << strStr("mississippi", "issip") << endl; // PC: return 4
    return 0;
}
