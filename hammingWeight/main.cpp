#include <iostream>
#include <bitset>

using namespace std;

class Solution {
public:
    int hammingWeight(int n)
    {
        bitset<32> binary(n);
        string binaryString = binary.to_string();
        cout << binaryString << endl;
        int setBits = 0;

        for (int i = 0; i<binaryString.size(); i++)
            {

                if (binaryString[i] == '1' )
                    {
                        cout << binaryString[i] << endl;
                        setBits += 1;
                    }
            }

        return setBits;
    }
};

int main()
{
    cout << "Hamming Weight!" << endl;
    Solution s1;
    cout << s1.hammingWeight(2147483645) << endl;
    return 0;
}
