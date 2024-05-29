#include <iostream>

using namespace std;

/**

1. What is the simplest problem
2. Play around with examples and visualise
3. Relate hard cases to simpler cases
4. Generalize the pattern
5. Write code by combing recusrive pattern using base case

*/

int partition(int n, int m)
{
    if (n == 0)
        {
            return 1;
        }
    else if ( n < 0 || m == 0)
        {
            return 0;
        }
    return partition(n-m,m) + partition(n,m-1);
}



int main()
{
    cout << "Partition n objects in m different ways!" << endl;
    cout << partition(1,1) << endl;
    cout << partition(1,2) << endl;
    cout << partition(1,3) << endl;
    cout << partition(2,2) << endl;
    cout << partition(3,2) << endl;
    cout << partition(2,3) << endl;
    cout << partition(3,3) << endl;
    cout << partition(5,5) << endl;


    return 0;
}
