#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
        Input: s = "Was it a car or a cat I saw?"
        Output: true

        Approach: 2 pointers
        pointerStart = s.begin()
        pointerEnd = s.end()

        if pointerstart  == pointerend:
            pointerstart forward
            pointerend backward
        else:
            return false


    */
    bool isPalindrome(string s)
    {
        int pointerOne = 0;
        int pointerTwo = s.size()-1;
        std::transform(s.begin(), s.end(), s.begin(),
                       [](unsigned char c){return std::tolower(c);});

        cout << s << endl;

        while (pointerOne < pointerTwo)
            {
                if (s[pointerOne] == s[pointerTwo])
                    {
                        // success
                        pointerOne += 1;
                        pointerTwo -= 1;
                    }
                else if (s[pointerOne] != s[pointerTwo] )
                    {
                        // Not equal but why?

                        if ((s[pointerOne] != s[pointerTwo])     && (isalnum(s[pointerOne] == 0 && isalnum(s[pointerTwo]) == 0))  )
                            {
                                pointerOne += 1;
                                pointerTwo -=1;
                            }
                        else if (isalnum(s[pointerOne]) == 0 )
                            {
                                pointerOne +=1;
                            }
                        else if (isalnum(s[pointerTwo]) == 0 )
                            {
                                pointerTwo -=1;
                            }
                        else if (s[pointerOne] != s[pointerTwo])
                            {
                                return false;
                            }
                    }
            }

        return true;
    }


    /*
    Approach: 2 pointers
    1 start at beg
    1 start at end

    input: 0 1 2 3 4
    Target: 5
    solution = <2,3>
    */
    public:
        vector<int> twoSum(const vector<int>& nums, int target)
    {
        int begPointer  = 0;
        int endPointer = nums.size()-1;

        while (begPointer != nums.size()-1)
            {
                if ((nums[begPointer] + nums[endPointer] == target))
                    {
                        vector<int> solutionIndices = {begPointer, endPointer};
                        return solutionIndices;

                    }

                if (begPointer < endPointer)
                    {
                        endPointer -=1;
                    }

                if (begPointer == endPointer)
                    {
                        endPointer = nums.size()-1;
                        begPointer +=1;
                    }
            }


        return {};

    }
};


int main()
{
    cout << "Hello world!" << endl;
    string s = "ABA";
    Solution s1;
    cout << s1.isPalindrome(s) << "\n";
    if ('w' == 'W')
        {
            cout << "Character Capatalisation does not count" << endl;
        }
    else
        {
            cout << "Yes, it doees \n";
        }
    return 0;
}
