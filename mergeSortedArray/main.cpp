#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]

Problem Analysis:
Given two vectors sorted in ascending order, where vector a contains m values not zero but is size m + n,
and vector b contains n values and is size n.
How can you merge vector b into vector a while maintaining the ascending order?

Program design:
What do we know? -> a is allocated additional size to accomdate n + entries from b.
We know that if we use a two pointer approach, we can compare an entry from a with an entry from b.
If we set some swap condition we can advance our pointer and repeat.
Once we read a zero from a we copy all remaining elements from b.

1) Create 2 pointers, each pointing to the start of the respective vectors.
2) Loop over vector a
3) Do the following comparison -> is a[ptr1] <= b[ptrb]
    4a) if we find that a[ptra] <= b[ptrb],no swapping, we advance ptra by 1 and repeat the process.
    4b) if we find that a[ptra] > b[ptrb], we swap a[ptra] and b[ptrb], we advance ptra b a and repeat the process.
5) If we read a 0 from a, we stop and copy the remainder of b into a.
6) We should now have a to be sorted in ascending order.







A simpler approach
insert nums2 into nums1
sort nums1
Remove n occurences of 0 from nums1
:)
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {

        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        std::sort(nums1.begin(),nums1.end());
        //nums1.erase(remove(nums1.begin(), nums1.end(),0), nums1.end());
        for(int i = 0; i < n; ++i) {
            auto it = std::find(nums1.begin(), nums1.end(), 0);
            if(it != nums1.end()) {
                nums1.erase(it);
            }
        }

    }
};
int main()
{
    vector<int> nums1 = {4,5,6,0,0,0};
    vector<int> nums2 = {1,2,3};
    //nums1.insert(nums1.end(), nums2.begin(),nums2.end());
    Solution s1;
    s1.merge(nums1,nums1.size(),nums2,nums2.size());

    return 0;
}
