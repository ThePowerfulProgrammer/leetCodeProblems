#include <iostream>
#include <string>
using namespace std;

int reverseInteger(int x) {
    int reversed = 0;

    while (x != 0) {
        // Extract the last digit
        int digit = x % 10;

        // Check for overflow or underflow
        if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && digit > 7))
            return 0;
        if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && digit < -8))
            return 0;

        // Append the digit to the reversed number
        reversed = reversed * 10 + digit;

        // Move to the next digit
        x /= 10;
    }

    return reversed;
}

int main()
{
    cout << "Hello world!" << endl;
    cout << reverseInteger(-123) << endl;
    cout << reverseInteger(120) << endl;
    return 0;
}
