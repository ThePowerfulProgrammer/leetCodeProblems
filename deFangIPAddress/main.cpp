#include <iostream>

using namespace std;


class Solution {
public:
    string defangIPaddr(string address)
    {
        for (int i=0;i<address.size(); i++)
            {
                if (address[i] == '.')
                    {
                        string replacement = "[.]";
                        address.replace(i,1,replacement);
                        i += 1;
                    }
            }

        return address;
    }
};

int main()
{
    cout << "DeFang an IPAddress !" << endl;


    Solution s1;
    cout << s1.defangIPaddr("1.1.1.1") << endl;
    cout << s1.defangIPaddr("255.100.50.0") << endl;
    return 0;
}
