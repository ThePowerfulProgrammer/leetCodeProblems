#include <iostream>

using namespace std;

/**

Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, \
and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Is this where I relearn long division? :(


divident/divisor = quotient

4/9
*/

int simpleDivison(int divident, int divisor)
{
    //
    int count = 0;
    int quotient = 0;
    while (divident > divisor)
    {
        while (divident - divisor > 0)
            {
                divident -= divisor;
                count += 1;
            }
        quotient = count;
        int subtractionValue = divisor * count;
        divident -= subtractionValue;
    }

    return quotient;
}

class Solution {
public:
    int divide(int dividend, int divisor)
    {
        return 0;
    }
};

int main()
{
    cout << "Recreate / " << endl;

    cout << simpleDivison(57,6) << endl;
    return 0;
}
