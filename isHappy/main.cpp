#include <iostream>
#include <set>

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
                        n /=10;
                    }
                n = sum;
                if (values.find(n) != values.end())
                    {
                        return false;
                    }
                values.insert(n);
            }
        return n == 1;
    }

private:
    set<int> values;
};

int main()
{
    cout << "is n Happy!" << endl;
    cout << "2 % 10 " << 2 % 10 << endl;
    Solution s1;
    cout << s1.isHappy(4);
    return 0;
}
