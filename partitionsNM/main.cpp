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
    if (n==0 || m == 0)
        {
            return 0;
        }
    if (n == 1 && m == 1)
        {
            return 1;
        }





    return 0;
}

int main()
{
    cout << "Partition n objects in m different ways!" << endl;
    return 0;
}
