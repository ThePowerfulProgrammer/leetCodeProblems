#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
};

template <class elemType>
void insertionSort(vector<elemType>& nums, int length)
{
     for (int firstOutOfOrder = 1; firstOutOfOrder < length; firstOutOfOrder++)
     {
        if (nums[firstOutOfOrder] < nums[firstOutOfOrder - 1])
             {
                 elemType temp = nums[firstOutOfOrder];
                 int location = firstOutOfOrder;
                 do
                 {
                     nums[location] = nums[location - 1];
                     location--;
                 } while(location > 0 && nums[location - 1] > temp);
                 nums[location] = temp;
            }
     }
}

double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    vector<int> nums3;
    nums3.insert(nums3.end(),nums1.begin(),nums1.end());
    nums3.insert(nums3.end(),nums2.begin(),nums2.end());
    insertionSort(nums3,nums3.size());
    for (int i:nums3)
        {
            cout << i << " ";
        }
    cout << endl;


    if (nums3.size() % 2 == 0)
        {
            cout << "Even" << endl;
            double medianPos = (nums3.size() + 1)/2.0;
            cout << medianPos << endl;
            double x = nums3[medianPos-0.5-1];
            double y = nums3[medianPos+0.5-1];
            cout << x + y << endl;
            return static_cast<double>(x+y)/2;
        }
    else
        {
            cout << "Odd" << endl;
            double medianPos = (nums3.size() + 1)/2.0;
            cout << std::fixed << std::setprecision(4) << medianPos << endl;
            return (nums3[medianPos-1] );
        }

    return 0;
}

int main()
{
    Solution s1;
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2};
    cout << s1.findMedianSortedArrays(nums1,nums2);
    return 0;
}
