#include <iostream>
#include <vector>

using namespace std;

// iteration 0
int isNumberPalindrome(int n)
{
    int initial = n;
    int reversedNumber = 0;
    int remainder;
    while (n != 0)
        {
            remainder = n%10;
            reversedNumber = reversedNumber * 10 + remainder;
            n /= 10;
        }

    return (reversedNumber == initial);
}

bool isPalindrome(int x) {
        string xToString = to_string(x);
        string xFlipped;
        for (int i=xToString.length()-1;i>=0;i--)
            {
                xFlipped += xToString[i];
            }
        cout << xToString << " == " << xFlipped << endl;
        return (xToString == xFlipped);
}



int main()
{

    cout << isPalindrome(321) << endl;
    cout << isPalindrome(121)<<endl;
    cout << isPalindrome(-121) << endl;

    return 0;
}
