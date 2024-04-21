#include <iostream>
#include <bitset>
using namespace std;


class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        bitset<32> binary(n);
        cout << binary << endl;
        string repr = binary.to_string() ;
        string reverseRepr = "";

        for (int i=repr.size() - 1; i>=0; i-- )
            {
                reverseRepr += repr[i];
            }
        cout << reverseRepr << endl;

        bitset<32> reverseBinary(reverseRepr);

        return reverseBinary.to_ulong();
    }
};

int main()
{
    cout << "Reverse 32 bits" << endl;
    Solution s1;

    cout << s1.reverseBits(00000010100101000001111010011100) << endl;
    return 0;
}
