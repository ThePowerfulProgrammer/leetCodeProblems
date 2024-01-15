#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// use the sliding windows technique to sum paris of size k
vector<int> sumPairs(vector<int> numbers, int k)
{
    int sum = accumulate(numbers.begin(),numbers.begin() + k,0);
    vector<int> result;
    result.push_back(sum);

    for (int i=1;i<numbers.size()-k+1;i++)
        {

            sum = sum - numbers[i-1]; // minus previous value
            sum = sum + numbers[i+k-1]; // add a window of size k
            result.push_back(sum);
        }

    return result;
}

// use the sliding windows technique to find the largest consectutive sum of size k
int findLargestSum(vector<int> numbers,int k)
{
    if (k > numbers.size())
        {
            return 0;
        }
    int sum = accumulate(numbers.begin(),numbers.begin()+k,0);
    int largest = sum;

    for (int i=1;i<numbers.size()-k+1;i++)
        {
            sum = sum - numbers[i-1];
            sum = sum + numbers[i+k-1];
            if (sum > largest)
                {
                    largest = sum;
                }
        }
    return largest;
}

int main()
{
    vector<int> numbers = { 5, 7, 1, 4, 3, 6, 2, 9, 2 };
    cout << "Find the largest sum of 5 consecutive entries, using the sliding windows technique!" << endl;

    sumPairs(numbers,2);

    cout << findLargestSum(numbers,2) << endl;
    return 0;
}
