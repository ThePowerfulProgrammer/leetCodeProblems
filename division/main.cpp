#include <iostream>
#include <cmath>

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


/**
Using shift and substract method
*/
int longDivision(int dividend, int divisor)
{

    if (dividend == INT_MIN && divisor == -1)
        {
            return INT_MAX;
        }

    bool isNegative = (dividend < 0) ^ (divisor < 0);

    long positiveDividend = static_cast<long>(abs(dividend));
    long positiveDivisor = static_cast<long>(abs(divisor));

    long current = 1;
    long denom = positiveDivisor;
    int answer = 0;

    while (positiveDividend >= denom)
    {
        denom <<= 1;
        current <<= 1;
    }
    denom >>= 1;
    current >>= 1;

    while (current != 0)
    {
        if (positiveDividend >= denom)
        {
            positiveDividend -= denom;
            answer |= current;
        }
        current >>= 1;
        denom >>= 1;
    }

    return isNegative ? -answer : answer;
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
    cout << longDivision(7,-3) << endl;
    return 0;
}
