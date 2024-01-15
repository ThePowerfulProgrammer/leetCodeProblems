#include <iostream>

using namespace std;

/**
Problem: Determine if string s represents a number (decimal || integer)

Description:
A valid number can be split up into these components (in order):

A decimal number or an integer.
(Optional) An 'e' or 'E', followed by an integer.

A decimal number can be split up into these components (in order):

(Optional) A sign character (either '+' or '-').
One of the following formats:
    One or more digits, followed by a dot '.'.
    One or more digits, followed by a dot '.', followed by one or more digits.
    A dot '.', followed by one or more digits.

An integer can be split up into these components (in order):

(Optional) A sign character (either '+' or '-').
One or more digits.

Problem Analysis:
        Understand the problem: What is the actual problem? -> A string consists of characters, do those characters together represent a number?
        Well what is a number? A number is either a decimal || an integer. An integer has two representations: int && e(int) || E(int)

        Devise a plan: What plan of attack will result in our victory? Do we need to break the problem into smaller sub-problems and solve each?
        --> Yes.
        What is the psuedoCode algorithm?
            Read in string.
            Read in and verify the first character, if first character is not [-,+,digit] --> return false
            We have determined first character and so far it is valid.
                Read next character, character must be a digit or a dot. if not --> return false
                String is still valid
                if we read a dot we can have an [E,e] followed by an integer
                Read next character, if we prior read a . we must read digits only. if not --> return false
                if we read a dot we can have an [E,e] followed by an integer
            End of decimal check

            An integer check
            Read in string
            Read in and verify first char, if char is not [+,-,d] return false
            So far string is valid
            next character read must be digit. if not --> return false
            next character can be a digit or an [E,e] and must be followed by an integer.


        Carry out the plan: Implement your plan by writing code to solve the problem. Make sure to test your code with different inputs to ensure that it works correctly.
        For this we will write a function


        Look back: After you have implemented your solution, take some time to look back and reflect on your solution. Did it work as expected?


Input:
    string s

Output:
    bool: true,false


Solution Theory:

*/

class Solution {
public:
    bool isNumber(string s) 
    {
        // return true if number else false
        string digits = "0123456789";
        string signs = "+-";
        string e = "eE";
        int dotCount = 0;

        if (s.length() == 1 && digits.find(s[0]) == string::npos)
        {
            return false; // initial check, s is length 1 and it is not a digit therefore fail
        }
        else if (s.length() == 1 && digits.find(s[0]) != string::npos) 
        {
            return true;
        } // s is length 1 and contains a digit
        else  // length is >= 1 and therefore requires more processing before we make a judgement 
        {
            for (int a = 0;a<s.length();a++) // begin processing 
            {
                if (a == 0 && digits.find(s[a])  == string::npos && signs.find(s[a]) == string::npos && s[a] != '.') 
                {
                    return false;
                } // first character validation end, first character is not a digit,sign,dot

                else if (s[0] == '.')
                {
                    for (int b = a+1; b<s.length(); b++) 
                    {
                        if (b == a+1 && b == s.length()) 
                        {
                            return false;
                        } // we read a . and nothing else remain

                        if (e.find(s[b]) != string::npos) 
                        {
                            if (digits.find(s[b-1]) == string::npos) 
                            {
                                return false;
                            } // .eirrelevant

                            if (b == s.length()-1) 
                            {
                                return false;
                            } // ".e"
                            for (int c = b+1; c<s.length();c++) 
                            {
                                if (c == b+1 && c == s.length() - 1 && digits.find(s[c]) == string::npos) 
                                {
                                    return false;
                                } // we read a .e or .E
                                
                                
                                if (c == b+1 && signs.find(s[c]) != string::npos) 
                                {
                                    for (int d = c+1; d<s.length();d++) 
                                    {
                                        if (d == c+1 && d == s.length()) 
                                        {
                                            return false;
                                        } // we read a .e(sign) or .E(sign) and nothing after
                                        else if (digits.find(s[d]) == string::npos) 
                                        {
                                            return false;
                                        } // we read a .e(sign) or .E(sign) and some point after processed a non-digit
                                    }
                                    return true; // we processed all character in the string and ended with e.g: .e(sign)d...
                                } // we have read .e(sign) or .E(sign)

                                if (digits.find(s[c]) == string::npos) 
                                {
                                    return false;
                                } // we read a .e || .E and somepoint after read a non-digit therefore we terminate or read a late e/E


                            } // we process the rest of the string searching for an int starting at b+1
                            return true; //.designd
                        } // we read an .e/E and must now read an integer
                        
                        if (digits.find(s[b]) == string::npos) 
                        {
                            return false;
                        } // we read a .ddd and at some point read a non-digit therefore terminate

                    } // we process the rest of the string starting from one char after a
                    return true;
                } // the first character is a . --> We check the following: A single dot, a series of digits followed by an e followed by an int, A single dot followed by a series of digits

                else if (a == 0 && signs.find(s[0]) != string::npos) 
                {
                    if (e.find(s[a+1]) != string::npos) 
                    {
                        return false;
                    } // signE
                    for (int b=a+1;b<s.length();b++) 
                    {
                        
                        if (b == a+1 && b == s.length()) 
                        {
                            return false;
                        } // string s consists of only a + therefore false

                        if (s[b] == '.') 
                        {
                            if (digits.find(s[b-1]) == string::npos && b == s.length()-1) 
                            {
                                return false;
                            } // (sign). therefore fail

                            if(digits.find(s[b-1]) == string::npos && digits.find(s[b+1]) == string::npos) 
                            {
                                return false;
                            }

                            for (int c = b+1;c<s.length();c++) 
                            {
                                if (c == b+1 && c == s.length()  && s.length() == 2) 
                                {
                                    return false;
                                } // +. therefore false

                                /*if (digits.find(s[c-1]) == string::npos) 
                                {
                                    return false
                                }*/

                                if (/*c != b+1 && */e.find(s[c]) != string::npos) 
                                {
                                    for (int d = c+1;d<s.length();d++) 
                                    {
                                        if (d == c+1 && d == s.length()) 
                                        {
                                            return false;
                                        } // we did not read an int after e

                                        if (d == c+1 && signs.find(s[d]) != string::npos) 
                                        {
                                            for (int e = d+1;e<s.length();e++) 
                                            {
                                                if (e == d+1 && e == s.length()) 
                                                {
                                                    return false;
                                                } // we read a +.ddde+ therefore fail
                                                else if (digits.find(s[e]) == string::npos) 
                                                {
                                                    return false;
                                                } // we read a non-digit

                                            } // traverse rest of string after +.ddde+
                                            return true; // of the form +.ddde+int
                                        } // we read a +.ddde+ must now read an integer

                                        if (digits.find(s[d]) == string::npos) 
                                        {
                                            return false;
                                        } // we read a +.ddedd(non-digit)

                                    } // we traverse the string after +.dde
                                    if (s.length() == 3 && e.find(s[2]) != string::npos) 
                                    {
                                        return false;
                                    } // +.e
                                    return true; // +.ddddeddddd

                                } // we have read a +.dde and must now read an int

                                if (digits.find(s[c]) == string::npos)//wh 
                                {
                                    return false;
                                } // we read a +. and some point after did not read a digit
                            } // we traverse one char after +. or +ddd.
                            return true; // we read a +.dddd

                        } // we read a +. or we read a +ddd.

                        if (digits.find(s[b]) == string::npos) 
                        {
                            if (e.find(s[b]) != string::npos) 
                            {
                                if (b == s.length()-1) 
                                {
                                    return false;
                                }
                                for (int c = b+1;c<s.length();c++) 
                                {
                                    if (c==b+1 && c==s.length()-1) 
                                    {
                                        if (s[s.length()-1] == 'e' || s[s.length()-1] == 'E' || digits.find(s[s.length()-1]) == string::npos) 
                                        {
                                            return false;
                                        }
                                    }
                                    if (c==b+1 && signs.find(s[c])) 
                                    {
                                        for (int d=c+1;d<s.length();d++) 
                                        {
                                            if (d == c+1 && d==s.length()-1) 
                                            {
                                                return false;
                                            }
                                            if (digits.find(s[d]) == string::npos) 
                                            {
                                                return false;
                                            }
                                        }
                                        return true;
                                    } // signDDesign
                                    if (c==b+1 && digits.find(s[c]) ==string::npos && signs.find(s[c]) ==string::npos) 
                                    {
                                        return false;
                                    }
                                }
                                return true;
                            }
                            if (e.find(s[b]) == string::npos) 
                            {
                                return false;
                            }
                        } // +ddd(non-digit)

                    } // we process the rest of the string starting from one char after +
                    return true; // +ddddd 

                } // first character is a + || - 

                else if (a == 0 && digits.find(s[0]) != string::npos ) 
                {
                    if (a + 1 == s.length()) 
                    {
                        return true;
                    } // string contains one digit
                    else 
                    {
                        for (int b = a+1;b<s.length();b++) 
                        {
                            if (s[b] == '.') 
                            {
                                for (int c = b+1;c<s.length();c++) 
                                {
                                    if (c == b+1 && c == s.length()) 
                                    {
                                        return true;
                                    } // we read a d. and end

                                    else if (e.find(s[c]) != string::npos) 
                                    {
                                        if (c == s.length()-1) 
                                        {
                                            return false;
                                        } // d.e therefore false

                                        for (int d = c+1; d<s.length();d++) 
                                        {
                                            if (d == c+1 && d == s.length()) 
                                            {
                                                return false;
                                            } // we read a d.e we could not find an int
                                            
                                            
                                            if (d == c+1 && signs.find(s[d]) != string::npos) 
                                            {
                                                for (int e = d+1; e<s.length();e++) 
                                                {
                                                    if (e == d+1 && e == s.length()) 
                                                    {
                                                        return false;
                                                    } // we read a d.esign and nothing after
                                                    else if (digits.find(s[e]) == string::npos) 
                                                    {
                                                        return false;
                                                    } // we read a d.esign and some point after processed a non-digit

                                                } // traverse after d.esign
                                                return true; // we processed all character in the string and ended with e.g: d.esignd

                                            } // we have read d.esign

                                            if (digits.find(s[d]) == string::npos && c == s.length() - 1) 
                                            {
                                                return false;
                                            } // we read a d.e || d.E and somepoint after read a non-digit therefore we terminate or read a late e/E
                                           
                                            if (digits.find(s[d]) == string::npos) 
                                            {
                                                return false;
                                            }

                                        } // start traversing d.e

                                        if (e.find(s[s.length()-1]) != string::npos || s[s.length()-1] == '.') 
                                        {
                                            return false;
                                        } // 5.7ee || 2.e7.
                                        return true;
                                    } // we read a d. and an e some point after d.de, we must now read an int
                                    
                                    else if(digits.find(s[c]) == string::npos) 
                                    {
                                        return false;
                                    }
                                } // traverse one char after the d.

                            } // we read a d. at some point
                            else if (e.find(s[b]) != string::npos) 
                            {
                                if (b == s.length()-1) 
                                {
                                    return false;
                                } // de therefore fail                                
                                for (int c = b+1;c<s.length();c++) 
                                {
                                    if (c == b+1 && signs.find(s[c]) != string::npos) 
                                    {
                                        if (c == s.length() - 1) 
                                        {
                                            return false;
                                        } // de(sign) nothing else therefore fail                                
                                        for (int d = c+1;d<s.length();d++) 
                                        {
                                            if (digits.find(s[d]) == string::npos) 
                                            {
                                                return false;
                                            } // we read a de(sign)dddnon-digit therefore false
                                        }
                                        return true; // something of the form de(sign)dddd
                                    } // we read a de(sign)
                                    if (digits.find(s[c]) == string::npos) 
                                    {
                                        return false;
                                    } // we read a dedd(non-digit)
                    
                                    
                                } // we traverse the string after de
                                return true;
                            } // we read a de
                            else if (digits.find(s[b]) == string::npos) 
                            {
                                return false;
                            } // dddnon-digit

                        } // traverse from one char after the first digit
                        return true; // ddddddd

                    } // more char after the digit

                } // first char is a digit
                
            } // Initial for-loop used to search entire string
        }
        return true; // If not false it must be true?

    }
};







bool isNumber(string s) // ".1" length = 2
{
    // return true if number else false
    string digits = "0123456789";
    string signs = "+-";
    string e = "eE";
    int dotCount = 0;

    if (s.length() == 1 && digits.find(s[0]) == string::npos)
    {
        return false; // initial check, s is length 1 and it is not a digit therefore fail
    }
    else if (s.length() == 1 && digits.find(s[0]) != string::npos) 
    {
        return true;
    } // s is length 1 and contains a digit
    else  // length is >= 1 and therefore requires more processing before we make a judgement 
    {
        for (int a = 0;a<s.length();a++) // begin processing 
        {
            if (a == 0 && digits.find(s[a])  == string::npos && signs.find(s[a]) == string::npos && s[a] != '.') 
            {
                return false;
            } // first character validation end, first character is not a digit,sign,dot

            else if (s[0] == '.')
            {
                for (int b = a+1; b<s.length(); b++) 
                {
                    if (b == a+1 && b == s.length()) 
                    { 
                        cout << "Gotchu bitch" << endl;
                        return false;
                    } // we read a . and nothing else remain

                    if (e.find(s[b]) != string::npos) 
                    {
                        for (int c = b+1; c<s.length();c++) 
                        {
                            if (c == b+1 && c == s.length() - 1) 
                            {
                                return false;
                            } // we read a .e or .E
                            
                            
                            if (c == b+1 && signs.find(s[c]) != string::npos) 
                            {
                                for (int d = c+1; d<s.length();d++) 
                                {
                                    if (d == c+1 && d == s.length()) 
                                    {
                                        return false;
                                    } // we read a .e(sign) or .E(sign) and nothing after
                                    else if (digits.find(s[d]) == string::npos) 
                                    {
                                        return false;
                                    } // we read a .e(sign) or .E(sign) and some point after processed a non-digit
                                }
                                return true; // we processed all character in the string and ended with e.g: .e(sign)d...
                            } // we have read .e(sign) or .E(sign)

                            if (digits.find(s[c]) == string::npos) 
                            {
                                return false;
                            } // we read a .e || .E and somepoint after read a non-digit therefore we terminate or read a late e/E


                        } // we process the rest of the string searching for an int starting at b+1
                    } // we read an .e/E and must now read an integer
                    
                    if (digits.find(s[b]) == string::npos) 
                    {
                        return false;
                    } // we read a .ddd and at some point read a non-digit therefore terminate

                } // we process the rest of the string starting from one char after a
                return true;
            } // the first character is a . --> We check the following: A single dot, a series of digits followed by an e followed by an int, A single dot followed by a series of digits

            else if (a == 0 && signs.find(s[0]) != string::npos) 
            {
                for (int b=a+1;b<s.length();b++) 
                {
                    if (b == a+1 && b == s.length()) 
                    {
                        return false;
                    } // string s consists of only a + therefore false

                    if (s[b] == '.') 
                    {
                        for (int c = b+1;c<s.length();c++) 
                        {
                            if (c == b+1 && c == s.length()  && s.length() == 2) 
                            {
                                return false;
                            } // +. therefore false

                            if (c != b+1 && e.find(s[c]) != string::npos) 
                            {
                                for (int d = c+1;d<s.length();d++) 
                                {
                                    if (d == c+1 && d == s.length()) 
                                    {
                                        return false;
                                    } // we did not read an int after e

                                    if (d == c+1 && signs.find(s[d]) != string::npos) 
                                    {
                                        for (int e = d+1;e<s.length();e++) 
                                        {
                                            if (e == d+1 && e == s.length()) 
                                            {
                                                return false;
                                            } // we read a +.ddde+ therefore fail
                                            else if (digits.find(s[e]) == string::npos) 
                                            {
                                                return false;
                                            } // we read a non-digit

                                        } // traverse rest of string after +.ddde+
                                    
                                        return true; // of the form +.ddde+int
                                    } // we read a +.ddde+ must now read an integer

                                    if (digits.find(s[d]) == string::npos) 
                                    {
                                        return false;
                                    } // we read a +.ddedd(non-digit)

                                } // we traverse the string after +.dde
                            
                                return true; // +.ddddeddddd

                            } // we have read a +.dde and must now read an int

                            if (digits.find(s[c]) == string::npos) 
                            {
                                return false;
                            } // we read a +. and some point after did not read a digit
                        } // we traverse one char after +. or +ddd.
                        
                        return true; // we read a +.dddd

                    } // we read a +. or we read a +ddd.

                    if (digits.find(s[b]) == string::npos) 
                    {
                        return false;
                    } // +ddd(non-digit)

                } // we process the rest of the string starting from one char after +

                return true; // +ddddd 

            } // first character is a + || - 

            else if (a == 0 && digits.find(s[0]) != string::npos) 
            {
                if (a == s.length()-1) 
                {
                    return true;
                } // string contains one digit
                else 
                {
                    for (int b = a+1;b<s.length();b++) 
                    {
                        if (s[b] == '.') 
                        {
                            for (int c = b+1;c<s.length();c++) 
                            {
                                if (c == b+1 && c == s.length()) 
                                {
                                    return true;
                                } // we read a d. and end

                                else if (e.find(s[c]) != string::npos) 
                                {

                                    for (int d = c+1; d<s.length();d++) 
                                    {
                                        if (d == c+1 && d == s.length()) 
                                        {
                                            return false;
                                        } // we read a d.e we could not find an int
                                        
                                        
                                        if (d == c+1 && signs.find(s[d]) != string::npos) 
                                        {
                                            for (int e = d+1; e<s.length();e++) 
                                            {
                                                if (e == d+1 && e == s.length()) 
                                                {
                                                    return false;
                                                } // we read a d.esign and nothing after
                                                else if (digits.find(s[d]) == string::npos) 
                                                {
                                                    return false;
                                                } // we read a d.esign and some point after processed a non-digit

                                            } // traverse after d.esign
                                            return true; // we processed all character in the string and ended with e.g: d.esignd

                                        } // we have read d.esign

                                        if (digits.find(s[c]) == string::npos) 
                                        {
                                            return false;
                                        } // we read a d.e || d.E and somepoint after read a non-digit therefore we terminate or read a late e/E


                                    } // start traversing d.e
                                    return true;
                                } // we read a d. and an e some point after, we must now read an int
                                
                                else if(digits.find(s[c]) == string::npos) 
                                {
                                    return false;
                                }
                            } // traverse one char after the d.

                        } // we read a d. at some point
                        else if (e.find(s[b]) != string::npos) 
                        {
                            if (b == s.length()-1) 
                            {
                                return false;
                            } // de therefore fail
                            for (int c = b+1;c<s.length();c++) 
                            {
                                if (c == b+1 && signs.find(s[c]) != string::npos) 
                                {
                                    if (c == s.length() - 1) 
                                    {
                                        return false;
                                    } // de(sign) nothing else therefore fail
                                    for (int d = c+1;d<s.length();d++) 
                                    {
                                        if (digits.find(s[d]) == string::npos) 
                                        {
                                            return false;
                                        } // we read a de(sign)dddnon-digit therefore false
                                    }
                                    cout << "de(sign)dddd" << endl;
                                    return true; // something of the form de(sign)dddd
                                } // we read a de(sign)
                                if (digits.find(s[c]) == string::npos) 
                                {
                                    return false;
                                } // we read a dedd(non-digit)
                                
                            } // we traverse the string after de
                            cout << "dedddd" << endl;
                            return true;
                        } // we read a de
                        else if (digits.find(s[b]) == string::npos) 
                        {
                            return false;
                        } // dddnon-digit

                    } // traverse from one char after the first digit
                    return true; // ddddddd

                } // more char after the digit

            } // first char is a digit
            
        } // Initial for-loop used to search entire string
    }
    return true; // IF not false, it must be true?

}
















//  Leetcode Ed
bool isNumberLC(string s) 
{
    // return true if number else false
    string digits = "0123456789";
    string signs = "+-";
    string e = "eE";
    int dotCount = 0;

    if (s.length() == 1 && digits.find(s[0]) == string::npos)
    {
        return false; // initial check, s is length 1 and it is not a digit therefore fail
    }
    else if (s.length() == 1 && digits.find(s[0]) != string::npos) 
    {
        cout << "just a digit" << endl;
        return true;
    } // s is length 1 and contains a digit
    else  // length is >= 1 and therefore requires more processing before we make a judgement 
    {
        for (int a = 0;a<s.length();a++) // begin processing 
        {
            if (a == 0 && digits.find(s[a])  == string::npos && signs.find(s[a]) == string::npos && s[a] != '.') 
            {
                return false;
            } // first character validation end, first character is not a digit,sign,dot

            else if (s[0] == '.')
            {
                for (int b = a+1; b<s.length(); b++) 
                {
                    if (b == a+1 && b == s.length()) 
                    {
                        cout << "Gotchu bitch";
                        return false;
                    } // we read a . and nothing else remain

                    if (e.find(s[b]) != string::npos) 
                    {
                       
                        for (int c = b+1; c<s.length();c++) 
                        {
                            if (c == b+1 && c == s.length()) 
                            {
                                return false;
                            } // we read a .e or .E
                            
                            
                            if (c == b+1 && signs.find(s[c]) != string::npos) 
                            {
                                for (int d = c+1; d<s.length();d++) 
                                {
                                    if (d == c+1 && d == s.length()) 
                                    {
                                        return false;
                                    } // we read a .e(sign) or .E(sign) and nothing after
                                    else if (digits.find(s[d]) == string::npos) 
                                    {
                                        return false;
                                    } // we read a .e(sign) or .E(sign) and some point after processed a non-digit
                                }
                                cout << "True again" << endl;
                                return true; // we processed all character in the string and ended with e.g: .e(sign)d...
                            } // we have read .e(sign) or .E(sign)

                            if (digits.find(s[c]) == string::npos) 
                            {
                                return false;
                            } // we read a .e || .E and somepoint after read a non-digit therefore we terminate or read a late e/E


                        } // we process the rest of the string searching for an int starting at b+1
                    } // we read an .e/E and must now read an integer
                    
                    if (digits.find(s[b]) == string::npos) 
                    {
                        return false;
                    } // we read a .ddd and at some point read a non-digit therefore terminate

                } // we process the rest of the string starting from one char after a
                return true;
            } // the first character is a . --> We check the following: A single dot, a series of digits followed by an e followed by an int, A single dot followed by a series of digits

            else if (a == 0 && signs.find(s[0]) != string::npos) 
            {
                for (int b=a+1;b<s.length();b++) 
                {
                    if (b == a+1 && b == s.length()) 
                    {
                        return false;
                    } // string s consists of only a + therefore false

                    if (s[b] == '.') 
                    {
                        if (digits.find(s[b-1]) == string::npos && b == s.length()-1) 
                        {
                            return false;
                        } // (sign). therefore fail

                        for (int c = b+1;c<s.length();c++) 
                        {
                            if (c == b+1 && c == s.length()  && s.length() == 2) 
                            {
                                return false;
                            } // +. therefore false

                            if (c != b+1 && e.find(s[c]) != string::npos) 
                            {
                                for (int d = c+1;d<s.length();d++) 
                                {
                                    if (d == c+1 && d == s.length()) 
                                    {
                                        return false;
                                    } // we did not read an int after e

                                    if (d == c+1 && signs.find(s[d]) != string::npos) 
                                    {
                                        for (int e = d+1;e<s.length();e++) 
                                        {
                                            if (e == d+1 && e == s.length()) 
                                            {
                                                return false;
                                            } // we read a +.ddde+ therefore fail
                                            else if (digits.find(s[e]) == string::npos) 
                                            {
                                                return false;
                                            } // we read a non-digit

                                        } // traverse rest of string after +.ddde+
                                        cout << " +.ddde+int" << endl;
                                        return true; // of the form +.ddde+int
                                    } // we read a +.ddde+ must now read an integer

                                    if (digits.find(s[d]) == string::npos) 
                                    {
                                        return false;
                                    } // we read a +.ddedd(non-digit)

                                } // we traverse the string after +.dde
                                cout << "+.dddeddd" << endl;
                                return true; // +.ddddeddddd

                            } // we have read a +.dde and must now read an int

                            if (digits.find(s[c]) == string::npos) 
                            {
                                return false;
                            } // we read a +. and some point after did not read a digit
                        } // we traverse one char after +. or +ddd.
                        cout << "+.ddd" << endl;
                        return true; // we read a +.dddd

                    } // we read a +. or we read a +ddd.

                    if (digits.find(s[b]) == string::npos) 
                    {
                        return false;
                    } // +ddd(non-digit)

                } // we process the rest of the string starting from one char after +
                cout << "+ddd" << endl;
                return true; // +ddddd 

            } // first character is a + || - 

            else if (a == 0 && digits.find(s[0]) != string::npos ) 
            {
                if (a + 1 == s.length()) 
                {
                    cout << "d" << endl;
                    return true;
                } // string contains one digit
                else 
                {
                    for (int b = a+1;b<s.length();b++) 
                    {
                        if (s[b] == '.') 
                        {
                            for (int c = b+1;c<s.length();c++) 
                            {
                                if (c == b+1 && c == s.length()) 
                                {
                                    cout << "Only d." << endl;
                                    return true;
                                } // we read a d. and end

                                else if (e.find(s[c]) != string::npos) 
                                {
                                    if (c == s.length()-1) 
                                    {
                                        return false;
                                    } // d.e therefore false

                                    for (int d = c+1; d<s.length();d++) 
                                    {
                                        if (d == c+1 && d == s.length()) 
                                        {
                                            return false;
                                        } // we read a d.e we could not find an int
                                        
                                        
                                        if (d == c+1 && signs.find(s[d]) != string::npos) 
                                        {
                                            for (int e = d+1; e<s.length();e++) 
                                            {
                                                if (e == d+1 && e == s.length()) 
                                                {
                                                    return false;
                                                } // we read a d.esign and nothing after
                                                else if (digits.find(s[d]) == string::npos) 
                                                {
                                                    return false;
                                                } // we read a d.esign and some point after processed a non-digit

                                            } // traverse after d.esign
                                            cout << "d.esignd" << endl;
                                            return true; // we processed all character in the string and ended with e.g: d.esignd

                                        } // we have read d.esign

                                        if (digits.find(s[c]) == string::npos) 
                                        {
                                            return false;
                                        } // we read a d.e || d.E and somepoint after read a non-digit therefore we terminate or read a late e/E


                                    } // start traversing d.e
                                    cout << "True here" << endl;
                                    return true;
                                } // we read a d. and an e some point after, we must now read an int
                                
                                else if(digits.find(s[c]) == string::npos) 
                                {
                                    return false;
                                }
                            } // traverse one char after the d.

                        } // we read a d. at some point
                        else if (e.find(s[b]) != string::npos) 
                        {
                            for (int c = b+1;c<s.length();c++) 
                            {
                                if (c == b+1 && signs.find(s[c]) != string::npos) 
                                {
                                    for (int d = c+1;d<s.length();d++) 
                                    {
                                        if (digits.find(s[d]) == string::npos) 
                                        {
                                            return false;
                                        } // we read a de(sign)dddnon-digit therefore false
                                    }
                                    cout << "de(sign)dddd" << endl;
                                    return true; // something of the form de(sign)dddd
                                } // we read a de(sign)
                                if (digits.find(s[c]) == string::npos) 
                                {
                                    return false;
                                } // we read a dedd(non-digit)
                            } // we traverse the string after de
                            cout << "dedddd" << endl;
                            return true;
                        } // we read a de
                        else if (digits.find(s[b]) == string::npos) 
                        {
                            return false;
                        } // dddnon-digit

                    } // traverse from one char after the first digit
                    cout << "All digits true" << endl;
                    return true; // ddddddd

                } // more char after the digit

            } // first char is a digit
            
        } // Initial for-loop used to search entire string
    }
    cout << "Catch all true" << endl;
    return true; // If not false it must be true?

}


int main()
{
    cout << "Hello world!" << endl;
    Solution s1;
    cout << s1.isNumber("0") << endl;
    string digits = "0123456789";
    string s = "0";
    for (int i=0;i<s.length();i++)
        {
            if ((i == 0) && (digits.find(s[i]) == string::npos))
                    {
                        cout << "digit is not here" << endl;
                    }
        }

    return 0;
}


