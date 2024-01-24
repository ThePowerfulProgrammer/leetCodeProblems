#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/*

Problem Analysis: Given a square matrix, we must determine the minimum sum of any falling path throught the matrix.
The minimum sum is the sum of indiviual entries from each column such that the entry is the lowest in that row
and the next entry is such that it
is either directly below OR below and to the left OR below to the right, of the previous entry.

Program Design:
    Algorithms & DS and Techniques:
        Algorithms we can consinder ->  Searching algo to find the lowest entry in a row
        Techniques we can consider -> Recursion +  DP -> Tabulation
        DS we can consider -> vector<vector<int>> to create our table

    1) If using Recursion we need a base cases(s) and recursive case
    2) We need to create a new Table(Matrix) which we will use to store 0's for nots and
    1's for yes.

    1) If I use Tabulation and iteration
    2) I create a table populate it with 0's
    3) I iterate throught the matrix and use the prior criteria to find sum elements





*/

int findLowest(int prev,int current,int next)
{

}



class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        // 1) Create the table and seed the initial values of 0
        vector<int> t(matrix.size(),0);
        vector<vector<int>> table(matrix.size(),t);

        // 2) I need to fill in the first row at some column the value 1 indicating the lowest value in the first row in the matrix
        vector<int> firstRow = matrix[0];

        int smallest = firstRow[0];
        int column = 0;

        for (int i=1;i<firstRow.size();i++)
            {
                if (firstRow[i] < smallest)
                    {
                        smallest = firstRow[i];
                        column = i;
                    }
            }
        table[0][column] = smallest; // I now set the first row in the table with the lowest value from the matrix, I also have the column i

        // 3) We now consinder all other rows in the matrix, we only consider cols such adhere to the requirements.
        for (int i=1;i<matrix.size();i++)
            {
                for (int j=0;j<matrix.size();j++)
                    {
                        if (column - 1 > -1) // bottom left
                            {

                            }
                    }
            }


        return 0;
    }
private:

};

std::vector<std::vector<int>> test(int n) {
  std::vector<int> t(n, 0); // Creating a vector 't' of size 'n' filled with 'n'
  std::vector<std::vector<int>> arr(n, t); // Creating a 2D vector 'arr' of size 'n x n' filled with vector 't'
  return arr; // Returning the 'n x n' matrix
}

int main()
{
    int n;
    cout << "Input an integer value: ";
    cin >> n; // Taking user input for the size of the matrix

    std::vector<std::vector<int>> result = test(n); // Calling the test function to create the 'n x n' matrix
    cout << "Create an n x n matrix by said integer:\n";

    // Print the elements of the created 'n x n' matrix
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      printf("%d ", result[i][j]); // Printing each element of the matrix
    printf("\n"); // Moving to the next row after each inner loop completes
    }

    return 0;
}
