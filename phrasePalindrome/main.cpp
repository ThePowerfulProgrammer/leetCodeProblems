#include <iostream>
#include <stack>
#include <ctype.h>
#include <string>


/**
1) Starting from the inital string:
b)    determine if alnum(character)
c)        if so first standardize via setting to lowercase
d)        push it to stackA
e)        we have stackA which top is the last char in the string

2) Start traversing from the first character of the string
a)    if character is alnum:
b)        compare (tolower(character) == topOfStack)
c)            if so:
d)                stack.pop()
e)                move character pointer to the next
f)            else:
g)                return false
h)    return true


*/

class Solution {
public:
    bool isPalindrome(string s)
    {
        // process 1
        for (char c: s)
            {
                if (isalnum(c))
                    {
                        characterStack.push((char)tolower(c));
                    }
            }

        // process 2
        for (char c: s)
            {
                if (isalnum(c))
                    {
                        if ((char)tolower(c) != characterStack.top())
                            {
                                return false;
                            }
                        else
                            {
                                characterStack.pop();
                            }
                    }
            }

        return true;
    }

private:
    stack<char> characterStack;
};



using namespace std;

int main()
{
    cout << "IS the phrase a palindrome?!" << endl;

    stack<char> characterStack;
    string testStr = "A man, a plan, a canal: Panama";


    for (char c: testStr)
        {
            if (isalnum(static_cast<int>(c)))
                {
                    characterStack.push((char)tolower(c));
                }

        }
    cout << "Stack has been created" << endl;


    // start process 2
    for (char current: testStr)
        {
            if (isalnum(current))
                {
                    if ((char)tolower(current) != characterStack.top())
                        {
                            cout << "fail" << endl;
                        }
                    else
                        {
                            characterStack.pop();
                        }
                }
        }

    cout << "All good" << endl;
    return 0;
}
