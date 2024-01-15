#include <iostream>
#include <cmath>

using namespace std;


int myAtoi(string s)
{
    // create some variables which we will be using
    char firstCharacter = '\0';
    bool defaultSign = false;
    string digits = "0123456789";
    int searchStart = -1;

    // read in string
    for (int c = 0;c<s.length();c++)
    {
        if (!firstCharacter)
            {
                if (s[c] == '+' || s[c] == '-' || digits.find(s[c]) != std::string::npos)
                    {
                        firstCharacter = s[c]; // +,-, or a digit
                        if (firstCharacter != '+' && firstCharacter != '-')
                            {
                                defaultSign = true; // our value is positive
                            }
                        searchStart = c;
                        break; // we grabbed our first char therefore no need for us to continue reading characters
                    }
                else if (s[c] != ' ')
                    {
                        return 0; // "    e12344"
                    }
            }
    }

    if (!firstCharacter)
        {
            return 0;
        }

    string restOfNumber(1,firstCharacter);

    for (int i=searchStart+1;i<s.length();i++)
        {
            if (digits.find(s[i]) != std::string::npos)  // grab digits from the string until we read a non-digit
                {
                    restOfNumber += s[i];
                }
            else
                {
                    break;
                }
        }

    long long number = 0; // we do not know how large our number may be therefore we need a long boiii

    for (int d = 0;d<restOfNumber.length();d++)
        {
            if (restOfNumber[d] != '+' && restOfNumber[d] != '-')
                {
                    int myInt = restOfNumber[d] - '0'; // coversion from char to int
                    number = number * 10 + myInt;
                    if (number > INT_MAX)
                        {
                            break;
                        }
                }
        }

    if (restOfNumber[0] == '+' || defaultSign)
        {
            if (number > INT_MAX)
                {
                    return INT_MAX;
                }
            else
                {
                    return number;
                }
        }
    else
        {
            if (-number < INT_MIN)
                {
                    return INT_MIN;
                }
            else
                {
                    return -number;
                }
        }
}







class Solution {
public:
int myAtoi(string s)
{

    char firstCharacter = '\0'; // +,-
    bool defaultSign = false;
    string digits = "0123456789";
    int searchStart = -1;

    // step 1: Read in string
    for (int c = 0;c<s.length();c++)
        {
            if (!firstCharacter)
                {
                    if (s[c] == '+' || s[c] == '-' || digits.find(s[c]) != std::string::npos)
                    {
                        firstCharacter = s[c]; // set to +,-,digit
                        if (firstCharacter != '+' && firstCharacter != '-') // our first char is a digit
                            {
                                defaultSign = true; // we use this later
                            }
                        searchStart = c; // Where we start the rest of our search
                        break;
                    }
                    else if(s[c] != ' ')
                        {
                            return 0;
                        }
                }
        }

    if (!firstCharacter)
        {
            return 0;
        }

    // step 2: Read characters as digits until we encounter a non-digit
    string restOfNumber(1,firstCharacter);

    for (int i=searchStart+1;i<s.length();i++)
        {

            if(digits.find(s[i]) != std::string::npos) // Grab digits until we encounter a non-digit
                {
                    restOfNumber += s[i];
                }
            else
                {
                    break; // inner most loop destroyed
                }
        }



    long long number = 0;
    for (int d = 0; d < restOfNumber.length(); d++)
    {
        if (restOfNumber[d] != '+' && restOfNumber[d] != '-')
        {
            int myInt = restOfNumber[d] - '0'; // conversion to int
            number = number * 10 + myInt;
            if (number > INT_MAX)
            {
                break;
            }
        }
    }

    // Step 4: Number validation
    if (restOfNumber[0] == '+' || defaultSign)
    {
        if (number > INT_MAX) {
            return INT_MAX;
        } else {
            return number;
        }
    }
    else
    {
        if (-number < INT_MIN)
        {
            return INT_MIN;
        }
        else
        {
            return -number;
        }
    }
}
};







int main()
{
    cout << "MyATOI!" << endl;
    cout << myAtoi("   -42");
    cout << endl;
    cout << myAtoi("+42");

    cout << endl;
    cout << myAtoi("4193 with words");

    cout << endl;
    cout << myAtoi("-0004193 with words");

    cout << endl;
    cout << myAtoi("00000-42a1234");

    cout << endl;
    cout << myAtoi("words and 987");
    cout << endl;

    /*std::string str = "words and 987";
    int intValue = std::stoi(str);
    std::cout << "Converted integer: " << intValue << std::endl;
*/
    cout << myAtoi(" ") << endl;

    return 0;
}
