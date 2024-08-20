#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

/**
Given an array of strings strs, group all anagrams together into sublists. You may return the output in any order.

An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.\
Input: strs = ["act","pots","tops","cat","stop","hat"]

Output: [["hat"],["act", "cat"],["stop", "pots", "tops"]]

possible solution:
    Starting from index 0, consider the word at strs[index]
    break the word into its constitute chars, from that index only move forward
        considering words at strs[index forward]
            if the chars that build that word are the same as the staring word -> Add it to a vector along with that word and repeat forward
                also add that index to an array so that we do not repeat considering it.

*/


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<int> indexesConsumed = {};
        vector<vector<string>> tableOfAnagrams;

        for (int i = 0; i < strs.size(); i++)
            {
                if (std::find(indexesConsumed.begin(), indexesConsumed.end(), i) == indexesConsumed.end())
                    {

                        vector<string> temp = {strs[i]};
                        set<char> characters = createCharacterSet(strs[i]);

                        for (int j=i+1;j<strs.size(); j++)
                            {
                                if (characters == createCharacterSet(strs[j]))
                                    {
                                        temp.push_back(strs[j]);
                                        indexesConsumed.push_back(j);
                                    }
                            }
                        tableOfAnagrams.push_back(temp);
                    }

            }

        return tableOfAnagrams;

    }

private:
    set<char> createCharacterSet(string s)
    {
        set<char> characters = {};
        for (char c: s)
            {
                characters.insert(c);
            }
        return characters;
    }
};



int main()
{
    cout << "Anagram Groups!" << endl;

    vector<string> strs = {"act","pots","tops","cat","stop","hat"};
    Solution s1;
    vector<vector<string>> output = s1.groupAnagrams(strs);

    for (auto v: output)
        {
            cout << "{";
            for (auto word : v)
                {
                    cout << word << ",";
                }
            cout << "}\n";
        }


    return 0;
}
