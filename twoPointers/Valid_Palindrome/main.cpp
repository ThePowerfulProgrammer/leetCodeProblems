#include <iostream>
#include <vector>
#include <cctype>

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
    string s = "Was it a car or a cat I saw?";
    Solution s1;
    s1.isPalindrome(s);
    return 0;
}
