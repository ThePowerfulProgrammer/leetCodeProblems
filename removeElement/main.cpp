#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int> nums, int val) {
    vector<int>::iterator it = nums.begin();
    int i = 0;
    while (i!=nums.size())
        {

            if (nums.at(i) == val)
                {
                    nums.erase(it+i);
                    i-=1;
                }

            i+=1;

        }
    return nums.size();
}

int main()
{
    cout << "Hello world!" << endl;
    cout << removeElement({1,1,3,4,5,1,1,2,3,4}, 1) << endl;
    cout << removeElement({1,1,1,1,1,1,1,1,1}, 1) << endl;


    return 0;
}
