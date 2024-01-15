#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;


/**
Test Case:
    "()"    1 - True
    "()[]{}"    2 - True
    "(]"        3 - False


(: Left parenthesis, ASCII code 40
): Right parenthesis, ASCII code 41
[: Left square bracket, ASCII code 91
]: Right square bracket, ASCII code 93
{: Left curly brace, ASCII code 123
}: Right curly brace, ASCII code 125


PA:
    Given a string consisting of only objects of type Parentheses.
    Determine whether the string is valid(Parentheses appear in order) or invalid(parentheses appear out of order)
      eg: Valid: {}()[] -> We notice after each P appear one after another
          Valid: {[]} -> We notice the P still appear in order.
      eg: Invalid: (] -> We notice the Parenthese do not have matching pairs(Do not appear in order)
          Invalid: { [) } -> THe outer is right but the inner is false

PD:
    Create a stack and push each element onto the stack.
    Once we done pushing all elements we begining popping(reading) elementa from the stack.
      We read an element (A):
        The following are the situations where we are false:
            The element after A is a left Parentheses -> Eg: (]
            There are no more elements on the stack we have an odd amount of letters -> Eg: ){}
        The following are the situations where we are true:
            The element after A is a right Parentheses -> We do the following:
                we can repeat the above -> Loop
                We eventually read a matching left Parenthese:
                    Must unwind in this fashion until we exhaust the stack:
                    We use the False cases to determine if the string is False. -> Eg: {([])}
            The Element after A is a matching Left Parentheses. -> []



*/


class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            switch (c) {
                case '(':
                case '{':
                case '[':
                    st.push(c);
                    break;
                case ')':
                    if (st.empty() || st.top() != '(') return false;
                    else st.pop();
                    break;
                case '}':
                    if (st.empty() || st.top() != '{') return false;
                    else st.pop();
                    break;
                case ']':
                    if (st.empty() || st.top() != '[') return false;
                    else st.pop();
                    break;
            }
        }
        return st.empty();
    }
};


int main()
{
    cout << "Valid Parentheses!" << endl;
    Solution s1;
    cout << s1.isValid("()[]{}");
    return 0;
}
