#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/**
    PA: Given a base x, and an exponent n, how do we find the x^n ?
    This is to be accomplished without using the pow(base,exponent) function

    Let us ignore programming and speak generally: A number(base) say 2 raised to some exponent say 2
    is equal to == 2^2
    2^2 == 2*2 == 4
    Let us try again with a negative number: 2^-2
    2^-2 == (2*2)*(1/2*2*2*2) == (4)*(1/16) == 4/16 == 1/4

    ** WE NOTICE THE FOLLOWING ALGORITHM **

    Given some number(base) be it positive/negative raised to some positive exponent is calculated using the following algorithm:

    if x != 0 and n > 0:
        x^n = (x * itself n times)                                               CASE 1
    else if x != 0 and n < 0:
        x^-n = (x * itself n times) * (1/x * itself 2n times)                    CASE 2
    else if x == 0:
        return 0                                                                 CASE 3
    else if x != 0 and n == 0:
        return 1                                                                 CASE 4


    ** WE WILL CREATE HELPER FUNCTIONS TO HANDLE THE UNIQUE CASES **
*/


class Solution {
public:

    double myPow(double x, int n);
private:
    double caseOne(double x, int n);

    float caseTwo(double x, int n);

    double caseThree();

    double caseFour();

    double caseFive();

    double caseSix();

};

//  Base and Positive exponent
double Solution::caseOne(double x, int n)
{
    if (x == 1)
        {
            return 1;
        }
    else if (x == -1 and n % 2 == 0)
        {
            return 1;
        }
    else if (x == -1 and n % 2 != 0 )
        {
            return -1;
        }
    double solution = x;
    for (int i = 1;i<n;i++)
        {
            solution *= x;
        }

    return solution;
}

// Base and Negative exponent
float Solution::caseTwo(double x, int n)
{
    if (x == 1)
        {
            return 1;
        }
    else if (x == -1 and n % 2 == 0)
        {
            return 1;
        }
    else if (x == -1 and n % 2 != 0 )
        {
            return -1;
        }
    double left = x;
    for (int i = -1;i>n;i--)
        {
            left *= x;
        }
    cout << "left after loop " << left << endl;

    double right = left;
    for (int i=0; i>n;i--)
        {
            right *= x;
        }
    cout << "right after loop " << right << endl;
    return (left/right);
}

// Base == 0
double Solution::caseThree()
{
    return 0;
}

// Base != 0 and Exponent == 0
double Solution::caseFour()
{
    return 1;
}

double Solution::myPow(double x, int n)
{
    if (x != 0 and n > 0)
        {

            return caseOne(x,n);
        }
    else if (x != 0 and n < 0)
        {
            cout << "caseTwo" << endl;
            return caseTwo(x,n);
        }
    else if (x == 0)
        {
            return caseThree();
        }
    else
        {
            return caseFour();
        }
}

int main()
{
    cout << "Pow function!" << endl;
    Solution s1;
    //cout << s1.myPow(2,2) << endl; // 4
    //cout << s1.myPow(3,-3) << endl; // 1/4
    /*double x = s1.myPow(0.25519,-6);
    double y = pow(0.25519,-6);
    cout << y << " == " << x << endl;*/
    cout << pow(2.00000, -2147483648) << endl;
    cout << pow(1.0000000000001,-2147483648) << endl;
    cout << pow(-1.00000, 2147483647) << endl;
    return 0;
}
