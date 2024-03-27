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


using namespace std;

int main()
{
    cout << "IS the phrase a palindrome?!" << endl;

    string testStr = "A man, a plan, a canal: Panama";
    testStr.

    for (char c: testStr)
        {
            if (isalnum(static_cast<int>(c)))
                {
                    cout << c << " ";
                }

        }
    return 0;
}
