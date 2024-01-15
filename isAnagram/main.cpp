#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool isAnagram(string s, string t) {
    unordered_map<char,int> characterList;

    for (int i=0;i<s.length();i++)
        {
            if (characterList.find(s[i]) == characterList.end())
                {
                    characterList[s[i]] = 1;
                }
            else
                {
                    characterList[s[i]] +=1;
                }
        }

    if (s.length() != t.length() )
        {
            return false;
        }

    for (int i=0;i<t.length();i++)
        {
            characterList[t[i]] -=1;
            if (characterList[t[i]] == -1)
                {
                    return false;
                }
            if (s.find(t[i]) == string::npos)
                {
                    return false;
                }

        }
    return true;
}

int main()
{
    cout << isAnagram("anagram", "nagaram") << endl;
    cout << isAnagram("car", "car") << endl;
    cout << isAnagram("car", "ccr") << endl;


    return 0;
}
