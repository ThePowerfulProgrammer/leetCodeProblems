#include <iostream>

using namespace std;

class Solution {
public:
    bool isHappy(int n)
    {
        while (n!=1)
            {
                int sum = 0;
                while (n > 0)
                    {
                        int value = n%10;
                        sum += value*value;
                        cout << "sum: " << sum << endl;
                        n /=10;

                        loops += 1;
                        if (loops == 10)
                            {
                                return false;
                            }
                    }
                n = sum;
            }
        return n == 1;
    }

private:
    int loops = 0;
};

int main()
{
    cout << "is n Happy!" << endl;

    Solution s1;
    cout << s1.isHappy(8);
    return 0;
}
