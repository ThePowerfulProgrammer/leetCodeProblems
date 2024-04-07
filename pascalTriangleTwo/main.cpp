#include <iostream>
#include <vector>
using namespace std;


/*
    If rowIndex == 1
    base case:
        return {1}
    if rowIndex == 2
    base case:
        return {1,1}

*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0)
        {
            return {1};
        }
        if(rowIndex==1)
        {
            return {1,1};
        }
        vector<int> first(2,1);
        int check=2;
        while(check<=rowIndex)
        {
            vector<int>second(check+1,1);
            for(int i=1;i<check;i++)
            {
                second[i]=first[i-1]+first[i];
            }
            first=second;
            check++;
        }
        return first;
    }
};


int main()
{
    cout << "ith Row Of Pascal's Triangle!" << endl;
    return 0;
}
