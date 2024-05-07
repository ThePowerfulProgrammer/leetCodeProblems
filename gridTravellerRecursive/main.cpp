#include <iostream>

using namespace std;

/**
Write a function that takes 2 inputs, n and m and returns the numer of unique paths from the top left to the
bottom right corner of an n x m Grid.

Constraint: You can only move down 1 or right one unit at a time.

1. What is the simplest problem
2. Play around with examples and visualise
3. Relate hard cases to simpler cases
4. Generalize the pattern
5. Write code by combing recusrive pattern using base case
*/


int gridTraveller(int n, int m)
{
    if (n == 0 && m == 0)
        {
            return 0;
        }

    if (n == 1 || m == 1)
        {
            return 1;
        }

    return gridTraveller(n-1,m) + gridTraveller(n,m-1);
}

int main()
{
    cout << "Grid traveller!" << endl;
    cout << gridTraveller(5,5) << endl;
    return 0;
}
