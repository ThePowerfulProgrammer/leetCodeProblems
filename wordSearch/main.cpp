#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/**
Problem Analysis:
If we are given a matrix of some size nxm.
And some word, we have to determine if we can find that word in the matrix, given the constraint that we can only move vertically and horizontally.

Program Design:
PsedoTalk:
We have to start somewhere in the matric to commence our search, we choose the first position matrix[0][0].

We chose a starting point and have begun our search, how do we determine if we should continue searching or move to the next pos?
We know we move horizontally or vertically.

We check the entry to the left matrix[0][0-1], entry to the right[0][0+1], entry above[0-1][0], and the entry below[0+1][0],
This of course assumes we can perform the nessecary arithemetic.

It any check we do not read the next nessecary letter, we terminate our search at that path.

We continue this from each entry until we either find the word or exhaust the matrix.

We still arent done. We now move to matrix[0][1], and repeat,
we do this until we find a solution or exhaust matrix[n][m].

TL;DR
Start at the top left -> Run a function that validates the vertical and horizontal neighbours,
ignore any non -matches and recongise the first match. At that match repeat the process until we find a solution or exhaust the matrix.

If we exhaust the matrix, we move to the next position and repeat the process, seeking a solution or exhausting the matrix.


1) Helper function
bool isvalid(position[][],letter)
{
    return position[][+1/-1] == letter
    OR
    return position[+1/-1] == letter
}


void FIND_SOLUTIONS( parameters):

if (valid solution):

store the solution

Return

for (all choice):

if (valid choice):

APPLY (choice)

FIND_SOLUTIONS (parameters)

BACKTRACK (remove choice)

Return
*/

void outputMatrix(vector<vector<char>>& board, char letter)
{
    for (const auto& v: board)
        {
            for (int i=0;i<v.size();i++)
                {
                    cout << v[i] << "|";
                }
            cout << endl;
            cout << "--------" << endl;
        }
}

/*class Solution {
public:
    // validate if next/previous row entry is the next letter or if next/previous col entry is the next letter

    bool isValid(vector<vector<char>>& board,auto row, int column,string word)
    {
        // base cases
        if (letterMatches == word.size())
            {
                return true;
            }
        if (board[row][column] != word[currentLetter])
            {
                return false;
            }

        // recursive case
        if (board[row][column] == word[currentLetter])
            {
                letterMatches +=1; // increment number of matches
                currentLetter +=1; // increment to the next index in word
                positionsConsidered[row].push_back(column); // row: column pairs

                if ((positionsConsidered.count(row) > 0 ) // ensure row exists for right check
                    {
                        auto it = find(positionsConsidered[row].begin(), positionsConsidered[row].end(), column + 1);
                        if (it == positionsConsidered[row].end() && column+1 < row.size()) // column+1 has not been considered
                            {
                                return isValid(board,row,column+1,word);
                            }
                    }
                if ((positionsConsidered.count(row+1) == 0) && (row+1 < board.size())) // Down check
                    {
                        return isValid(board,row+1,column,word);
                    }
                if (positionsConsidered.count(row) > 0) // Left Check
                    {
                        auto it = find(positionsConsidered[row].begin(), positionsConsidered[row].end(), column - 1);
                        if (it == positionsConsidered[row].end() && column - 1>0)
                            {
                                return isValid(board,row,column-1,word);
                            }
                    }
                if ((positionsConsidered.count(row-1) == 0) && (row-1 > 0)) // Top check
                    {
                        return isValid(board,row-1,column,word);
                    }
            }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word)
    {
        for (const auto& row:board)
            {
                for (int col=0;col<row.size();col++)
                    {
                        if (row[col] == word[currentLetter])
                            {
                                letterMatches +=1;
                                currentLetter +=1;
                                bool valid = isValid(board,currentRow,col,word);
                            }
                    }
                if (valid)
                    {
                        return true;
                    }
                else
                    {
                        positionsConsidered.clear();
                    }
                currentRow +=1;
            }
        return false;
    }

private:
    int letterMatches = 0; // default
    int currentLetter = 0; // default set to inde the first char in word
    map<int,vector<int>> positionsConsidered; // row maps to column entries
    int currentRow = 0; // keep track of which row we are currently traversing
};*/


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        bool valid = false;
        for (const auto& row : board)
        {
            for (int col = 0; col < row.size(); col++)
            {
                if (row[col] == word[currentLetter])
                {
                    letterMatches += 1;
                    currentLetter += 1;
                    valid = isValid(board, currentRow, col, word);
                }
            }
            if (valid)
            {
                return true;
            }
            else
            {
                positionsConsidered.clear();
            }
            currentRow += 1;
        }
        return false;
    }

private:

    bool isValid(vector<vector<char>>& board, int row, int column, string word)
    {
        // base cases
        if (letterMatches == word.size())
        {
            return true;
        }
        if (board[row][column] != word[currentLetter])
        {
            return false;
        }

        // recursive case
        if (board[row][column] == word[currentLetter])
        {
            letterMatches += 1; // increment number of matches
            currentLetter += 1; // increment to the next index in word
            positionsConsidered[row].push_back(column); // row: column pairs

            if (positionsConsidered.count(row) > 0) // ensure row exists for right check
            {
                auto it = find(positionsConsidered[row].begin(), positionsConsidered[row].end(), column + 1);
                if (it == positionsConsidered[row].end() && column + 1 < board[0].size()) // column+1 has not been considered
                {
                    return isValid(board, row, column + 1, word);
                }
            }
            if (positionsConsidered.count(row + 1) == 0 && row + 1 < board.size()) // Down check
            {
                return isValid(board, row + 1, column, word);
            }
            if (positionsConsidered.count(row) > 0) // Left Check
            {
                auto it = find(positionsConsidered[row].begin(), positionsConsidered[row].end(), column - 1);
                if (it == positionsConsidered[row].end() && column - 1 >= 0)
                {
                    return isValid(board, row, column - 1, word);
                }
            }
            if (positionsConsidered.count(row - 1) == 0 && row - 1 >= 0) // Top check
            {
                return isValid(board, row - 1, column, word);
            }
        }
        return false;
    }

    int letterMatches = 0; // default
    int currentLetter = 0; // default set to inde the first char in word
    map<int, vector<int>> positionsConsidered; // row maps to column entries
    int currentRow = 0; // keep track of which row we are currently traversing
};

int main()
{
    cout << "WordSearch -> Backtracking -> Medium !" << endl;
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    vector<vector<char>> board2 = {{'a','b'}};

    outputMatrix(board,'A');
    cout << endl;
    Solution s1;
    cout << s1.exist(board,"ABCCED");
    return 0;
}
