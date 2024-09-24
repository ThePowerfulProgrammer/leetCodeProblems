#include <iostream>
#include <cmath>
#include <typeinfo>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n)
    {
        if (n == 1)
            {
                return true;
            }
        else if (n == 0)
            {
                return false;
            }

        while (std::floor(n/2.0) == (n/2.0))
            {
                if (n != 2)
                    {
                        n = n/2.0;
                    }
                else
                    {
                        return true;
                    }
            }

        return false;

    }
};

int main()
{
    cout << "Is Power of 2?" << endl;

    Solution s1;

    cout << s1.isPowerOfTwo(0);
    return 0;
}
