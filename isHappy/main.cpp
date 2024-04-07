#include <iostream>

using namespace std;

class Solution {
public:
    bool isHappy(int n)
    {
        // create the initial sum
        while (n > 0)
            {
                digit += (n%10)*(n%10);
                n /=10;
            }
        cout << digit << endl;

        int tempSum = digit;
        while (tempSum > 0)
            {
                while (digit > 0)
                    {

                    }
            }
       return true;
    }

private:
    int digit = 0;
};

int main()
{
    cout << "is n Happy!" << endl;

    Solution s1;
    s1.isHappy(19);
    return 0;
}
