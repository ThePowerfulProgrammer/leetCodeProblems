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

// sum all the entires in a 3d matrix
int sum3DMatrix(vector<vector<int>> grid)
{
    int sum = 0;

    for (int i=0;i<grid.size();i++)
        {
            for (int j=0;j<grid.size();j++)
                {
                    sum += grid[i][j];
                }
        }
    return sum;

}


// returns [index,row[index]] row[index] is the lowest value
vector<int> leftMidRight(vector<int> row ,int prev,int current,int next)
{
    vector<int> indexAndValue;
    if (row[prev] <= row[current] && row[prev] <= row[next])
        {
            indexAndValue.push_back(prev); // column
            indexAndValue.push_back(row[prev]); // value
            // vector = {column,value}
            return indexAndValue;
        }
    else if (row[current] <= row[prev] && row[current] <= row[next])
        {
            indexAndValue.push_back(current); // column
            indexAndValue.push_back(row[current]); // value
            // vector = {column,value}
            return indexAndValue;
        }

    indexAndValue.push_back(next); // column
    indexAndValue.push_back(row[next]); // value
    // vector = {column,value}
    return indexAndValue;

}

vector<int> midNext(vector<int> row, int current,int next)
{
    vector<int> indexAndValue;

    if (row[current] <= row[next] )
        {
            indexAndValue.push_back(current); // column
            indexAndValue.push_back(row[current]); // value
            // vector = {column,value}
            return indexAndValue;
        }

    indexAndValue.push_back(next); // column
    indexAndValue.push_back(row[next]); // value
    // vector = {column,value}
    return indexAndValue;

}

vector<int> leftMid(vector<int> row, int prev,int current)
{
    vector<int> indexAndValue;

    if (row[prev] <= row[current] )
        {
            indexAndValue.push_back(prev); // column
            indexAndValue.push_back(row[prev]); // value
            // vector = {column,value}
            return indexAndValue;
        }

    indexAndValue.push_back(current); // column
    indexAndValue.push_back(row[current]); // value
    // vector = {column,value}
    return indexAndValue;
}

/* algorithm
vector<int> findLowest(vector<int> row)
{
    vector<int> indexAndValue;
    // Find the iterator pointing to the lowest element in the vector
    auto it = min_element(row.begin(), row.end());
    // Get the index of the lowest element
    int index = distance(row.begin(), it);
    // Get the value of the lowest element
    int value = *it;
    // Push the index and value to the vector
    indexAndValue.push_back(index); // column
    indexAndValue.push_back(value); // value
    // vector = {column,value}
    return indexAndValue;
}*/


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
        cout << table[0][column] << endl;
        cout << "column: " << column << endl;
        // 3) We now consinder all other rows in the matrix, we only consider cols such adhere to the requirements.
        for (int i=1;i<matrix.size();i++)
            {
                for (int j=0;j<matrix.size();j++)
                    {
                        if ( (column - 1 > -1) && (column + 1 < matrix.size()) ) // if there is pre and post there is a hypo
                            {
                                // I need some function to process all 3 entires, find the lowest and return the lowest and it's column value
                                vector<int> valueAndIndex = leftMidRight(matrix[i],column-1,column,column+1 );

                                // I update column to the above column and add the lowest to my table
                                column = valueAndIndex[0];
                                cout << column << endl;
                                cout << "value to be added: " << matrix[i][column] << endl;
                                table[i][column] = matrix[i][column];

                                // I then break out of the innermost loop and repeat the above for the next row
                                break;
                            }
                        else if ( (column - 1 > -1 )&& (column + 1 >= matrix.size()) ) // only a pre and hypo
                            {
                                // I need some function to process the prev col and current col
                                vector<int> valueAndIndex = leftMid(matrix[i],column-1,column);

                                // I update column and add lowest to my table
                                column = valueAndIndex[0];
                                cout <<  "value to be added: " << matrix[i][column] << endl;
                                table[i][column] = matrix[i][column];

                                // I then break out of the innermost loop and repeat the above for the next loop
                                break;
                            }
                        else if ( (column + 1 < matrix.size()) && (column - 1 < 0 )) // only a hypo and post
                            {
                                // I need some function to process the current col and next col
                                vector<int> valueAndIndex = midNext(matrix[i],column,column+1);

                                // I update column and add lowest to my table
                                column = valueAndIndex[0];
                                cout << "value to be added: " << matrix[i][column] << endl;
                                table[i][column] = matrix[i][column];

                                // I then break out of the innermost loop and repeat the above for the next loop
                                break;
                            }
                        cout << "inner loop: " << j << endl;
                    }
                cout << "outer loop: " << i << endl;
            }

        // 4) My table is now updated with values other than 0
        // I now return the sum(matrix) -> I would have to traverse the entire table, but I notice that I am not really using the table
        // I can create a regular vector and add values and return sum(vector)


        return sum3DMatrix(table);
    }

};



std::vector<std::vector<int>> test(int n) {
  std::vector<int> t(n, 0); // Creating a vector 't' of size 'n' filled with 'n'
  std::vector<std::vector<int>> arr(n, t); // Creating a 2D vector 'arr' of size 'n x n' filled with vector 't'
  return arr; // Returning the 'n x n' matrix
}




int minFallingPathSum(vector<vector<int>>& matrix)
{
    // 1) Create the table and seed the initial values of 0
    vector<int> t(matrix.size(),0);
    vector<vector<int>> table(matrix.size(),t);

    int smallest = matrix[0][0];
    int column = 0;


}







int main()
{
    int n;
    cout << "Input an integer value: ";
    //cin >> n; // Taking user input for the size of the matrix
    n = 2;
    std::vector<std::vector<int>> result = test(n); // Calling the test function to create the 'n x n' matrix
    cout << "Create an n x n matrix by said integer:\n";

    // Print the elements of the created 'n x n' matrix
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      printf("%d ", result[i][j]); // Printing each element of the matrix
    printf("\n"); // Moving to the next row after each inner loop completes
    }
    cout << endl;

    vector<int> example = {3,2,1};
    vector<int> solution = midNext(example, 1,2);
    cout << " Index: "<< solution[0] << " Value: " << solution[1] << endl;

    vector<vector<int>> table = {
        {1,2,3},
        {2,2,2},
        {1,1,1},
    };

    cout << sum3DMatrix(table) << endl;

    cout << endl << endl << endl;
    Solution s1;
    vector<vector<int>> matrix = {
        {2,1,3},
        {6,5,4},
        {7,8,9}
        };
    cout << s1.minFallingPathSum(matrix) << endl;

    vector<vector<int>> case1 = {
        {100,-42,-46,-41},
        {31,97,10,-10},
        {-58,-51,82,89},
        {51,81,69,-51}
        };


    vector<int> row1 = case1[0];
    int smallest = row1[0];
    int column = 0;
    cout << "size: " << row1.size() << endl;
    for (int i=1;i<4;i++) {
        if (row1[i] < smallest) {
            smallest = row1[i];
            column = i;
        }
    }

    cout << "Samllest: " << smallest << " column: " << column << endl;

    if (-41 < -46) {
        cout << "WTF" << endl;
    }

    cout << s1.minFallingPathSum(case1) << endl;

/*
[[100,-42,-46,-41],[31,97,10,-10],[-58,-51,82,89],[51,81,69,-51]]
*/
    return 0;
}
