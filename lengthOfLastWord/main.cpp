#include <iostream>

using namespace std;

class Solution {
    public:
        int lengthOfLastWord(string s);
};

// Function that returns index of last " "
int findLastSpace(string fullName)
{
    int spacePos;
    int location = 0;

    while (location != -1)
    {
        location = fullName.find(' ', location+1);
        if (location != -1)
        {
            spacePos = location;
        }
    }
    return spacePos;
}

// luffy is still joyboy
int Solution::lengthOfLastWord(string s)
{

    string word = "";
    string copyWord = "";
    for (int i=0;i<s.size();i++)
        {
            if (s[i] != ' ')
                {
                    word += s[i];
                }
            else
                {
                    if (word != "")
                        {
                            copyWord = word;
                        }
                    word = "";
                }
        }

    if (word.size() == 0)
        {
            return copyWord.size();
        }
    return word.size();
}

int main()
{
    cout << "Hello world!" << endl;
    cout << findLastSpace("Hello World" ) << endl;
    cout << "luffy is still joyboy" << endl;
    cout << findLastSpace("luffy is still joyboy") << endl;
    cout <<  "   fly me   to   the moon  " << endl;
    cout << findLastSpace("   fly me   to   the moon  ") << endl;
    Solution s1;
    cout << s1.lengthOfLastWord("luffy is still joyboy");
    return 0;
}
