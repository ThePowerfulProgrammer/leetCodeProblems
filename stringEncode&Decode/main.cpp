#include <iostream>
#include <vector>
#include <random>
#include <string>

using namespace std;

/*
String Encode and Decode
Design an algorithm to encode a list of strings to a single string. The encoded string is then decoded back to the original list of strings.

Please implement encode and decode

*/

class Solution {
public:

    int generateRandomValue()
    {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist6(1,100);

        return dist6(rng);
    }

    string encode(vector<string>& strs)
    {
        string encoded = "";
        vector<string>::iterator i;
        for (i = strs.begin(); i != strs.end(); ++i)
            {
                encoded += *i;
                string temp = *i;
                encodedPositions.push_back(temp.length());
            }
        return encoded;

    }

    vector<string> decode(string encoded) // should be string s
    {
        vector<string> decoded = {};
        int idx = 0;
        for (int i=0;i<encodedPositions.size();i++)
            {
                // grab the index of each word in the encoded word
                string temp = encoded.substr(idx,encodedPositions[i]);
                decoded.push_back(temp);
                idx += encodedPositions[i];
            }

        return decoded;
    }

    void printPos()
    {
        for (int i=0;i!=encodedPositions.size(); i++)
            {
                cout << encodedPositions[i] << "\n";
            }
    }

private:
    vector<int> encodedPositions = {};
};


int main()
{
    cout << "String encode and decode!" << endl;

    vector<string> words = {"neet","code","love","you"};


    Solution s1;
    string encoded = s1.encode(words);
    s1.printPos();
    vector<string> decoded = s1.decode(encoded);

    for (auto str: decoded)
        {
            cout << "word: " << str << "\n";
        }


    return 0;
}
