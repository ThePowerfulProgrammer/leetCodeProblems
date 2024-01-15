#include <iostream>
#include <vector>

using namespace std;

// iteration 0: find distance
/*
int removeDuplicates(vector<int> nums)
{
    // first unique value is set in loop
    int uniqueFirst = nums.front();
    // Used to set unqiueSecond and find distance
    int index = 1;
    // second unique value is set in loop
    int uniqueSecond;

    for (int i=0;i<nums.size();i++)
        {

            if (i != nums.size()-1) {
                while (nums[i+index] == nums[i])
                    {
                        index += 1;
                    }
                uniqueSecond = nums[i+index];
            }
            else
                {
                    uniqueSecond = 0;
                }

            // we now have set two unique values, Now we calculate the distance between them using index
            //1,1,1,2


            if (index > 2)
                {
                    nums.erase(nums.begin()+i,nums.begin()+(index-2));
                }
            cout << "First: " << uniqueFirst << " Second: " << uniqueSecond << endl;
            uniqueFirst = uniqueSecond;
            cout << "index: " << index << endl;

            index = 1;

        }
    for (auto num: nums)
        {
            cout << "num: " << num << ",";
        }

    return 0;
}*/

// iteration 1: find all unqiue elements
int removeDuplicates(vector<int> nums)
{
    int firstUnique = nums.front();
    int secondUnique = firstUnique;
    int position = 0;
    int index = 1;

    while (secondUnique != nums.back())
        {
            while (nums[position+index] == firstUnique)
                {
                    index +=1;
                }

            secondUnique = nums[position+index];
            cout << "First: " << firstUnique << " ---- " << position << "-"<< index << " ----- "<< " Second: " << secondUnique << endl;

            firstUnique = secondUnique;
            position = position + index;
            index = 1;
        }
    return 0;
}

// iteration 2: If element appears more than twice, all addtional entries are removed {a,a,a,a} => {a,a}
int removeDuplicatesTest2(vector<int> nums)
{
    int firstUnique = nums.front();
    int secondUnique = firstUnique;
    int position = 0;
    int index = 1;

    while (position + index < nums.size() && secondUnique != nums.back())
        {
            while (nums[position + index] == firstUnique)
                {
                    index +=1;
                }
            secondUnique = nums[position+index];
            cout << "First: " << firstUnique << " ---- " << position << "-" << index << " ----- " << " Second: " << secondUnique << endl;

            if (index > 2) {
                cout << "Length pre erasure: " << nums.size() << endl;
                nums.erase(nums.begin() + position + 2, nums.begin() + position + index);
                cout << "Length post erasure: " << nums.size() << endl;

                // Update variables for the next iteration based on the updated vector
                index = 1;
                secondUnique = nums[position + index];
            }
            else {
                // Update variables for the next iteration
                firstUnique = secondUnique;
                position += index;
                index = 1;
            }
        }

    for (int &num: nums)
        {
            cout << num << " " ;
        }
    cout << endl;
    return 0;
}


int main()
{

    vector<int> nums = {1,1,1,1,1,1,1,1,1,2,3,3,3,3,3,3,4,4,4,4,5,5,5,6,6,6,6};
    vector<int> nums1 = {1};
    vector<int> nums2 = {1,2,3,4,5};
    vector<int> nums3 = {1,1,1,1,1,1};

    cout << removeDuplicatesTest2(nums) << endl;
    //cout << removeDuplicates(nums1) << endl;
    //cout << removeDuplicates(nums2) << endl;
    cout << removeDuplicatesTest2(nums3) << endl;
    return 0;
}
