#include <iostream>

using namespace std;

/**
I will use newtons method

Xn = 1/2(Xn+x/Xn)

Xn = approximation
X = value
*/


class Solution {
public:
    int mySqrt(int x)
    {
        int n = x;
        cout << "Initial approximation: " << n << endl;
        while (n*n > x)
            {
                n = 0.5 * (n+x/n);
                cout << n << " ";
            }
        cout << "Final Approximation: " << endl;
        return n;

    }
};

int main()
{
    Solution s1;
    cout << s1.mySqrt(0) << endl;
    return 0;
}
