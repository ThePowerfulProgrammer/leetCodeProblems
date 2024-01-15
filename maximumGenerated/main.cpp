#include <iostream>

using namespace std;

/*
Here’s how the elements of nums are determined:

nums[0] = 0: The first element of the array is always 0.
nums[1] = 1: The second element of the array is always 1.
nums[2 * i] = nums[i] when 2 <= 2 * i <= n: For even indices in the array (2, 4, 6, etc.), the value is the same as the value at half that index. For example, nums[4] would be the same as nums[2].
nums[2 * i + 1] = nums[i] + nums[i + 1] when 2 <= 2 * i + 1 <= n: For odd indices in the array (3, 5, 7, etc.),
the value is the sum of the values at index i and i + 1. For example, nums[5] would be the sum of nums[2] and nums[3].
*/

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
