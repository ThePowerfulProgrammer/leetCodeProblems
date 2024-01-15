#include <iostream>
#include <vector>

using namespace std;

/**
        build a table using tabulation
        Then can I use past table entries to build future table entries.
        word = 'leetcodecode'
        array = [leet,code]

        TO Memoize is to store past results to use in future computations.
        If I store past results how can I use it?
        Current word in consideration ->  I can append other elements until the resultant word is less or equal in length to the target word.

        Current working logic:
        Selected word from array: Append every word from array to it and store for future building.
        We repeat the process until we construct a word == requiredWord
        OR
        All of the constructedWord is greater in length than requiredWord.
        We do not consinder words than are longer in length that requiredWord to build further solutions.

        Example run:

        ConsideredWord: leet
        concatenatedWords = [leetleet,codeleet,leetcode]
        Words not considered --> leetleet
        No success

        ConsideredWord: code
        concatenatedWords = [leetleet,codeleet,leetcode,codecode]
        Words not considered --> leetcode
        No success

        ConsideredWord: leet
        concatnatedWords = [leetleetleet,codecodeleet,leetcodecode]
        Success Found: leetcodecode

        If I use a vector to DP.
        I can store each unique Concatenated word to the vector.
        While remembering each instance from array will always occupy size(array) in the vector.

        I can continue building words until I reach a success condition or reach all word sizes greater than word.

        Finally the computing logic:
        Loop over the wordDict to grab each instance of a string (word):
            then loop over the wordDict again but this time create a sum of words:
                a + b = c
                first a will be from the 2nd loop
                second b will be from the 2nd loop
                this way we create a word that is the concatenation of both left and right.
                We check if the word is not already in the vector. If so: Do not add
                else: add

Overarching logic:
    I store sums of words:
    if the sum has been encountered before, I do not store it again.
    I constantly add to the indiviual sums until I find the word or all the sums are greater than word


However:
Memoisation is a DP Technique and it is one that relies on recursion:
Therefore I need a base case and a recursive case

Base case(s)

*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        int m = board.size(); // number of rows
        int n = board[0].size(); // number of columns in any row

        int index = 0; // Position in the board

        vector<vector<int>> visited(m,vector<int>(n,0)); // The solution board we look to build

        string ds = "";

        for (int row = 0;row<m;row++) // iterate all rows
            {
                for (int col=0;col<n;col++) // iterate all columns
                    {
                        if(board[row][col]==word[index] && solve(index+1,row,col,m,n,board,word,ds+board[row][col],visited)) // Where we begin our recursion
                           {
                               return true;

                           }
                    }
            }

        return false;

    }

private:
    //   Where we are,current row,current col,row pos,col,pos,board,the considered word,built word,visited vector
    bool solve(int index,int row,int col,int m,int n ,vector<vector<char>>&board,string word,string ds,vector<vector<int>>&visited)
    {
        // required base case
        if (index == word.size())
            {
                return true;
            }

        // edge cases
        if (row<0|col<0|row>=m|col>=n)
            {
                return false;
            }

        //down
        if(row+1<m && visited[row+1][col]==0 && board[row+1][col]==word[index])
        {

            visited[row][col]=1;

            bool ans1=solve(index+1,row+1,col,m,n,board,word,ds+board[row][col],visited);

            if(ans1==true){
                return true;
            }

            visited[row][col]=0;
        }

        //left
        if(col-1>=0 && visited[row][col-1]==0 && board[row][col-1]==word[index])
        {
            visited[row][col]=1;

            bool ans2=solve(index+1,row,col-1,m,n,board,word,ds+board[row][col],visited);

            if(ans2==true){
                return true;
            }

            visited[row][col]=0;
        }

        //right
        if(col+1<n && visited[row][col+1]==0 && board[row][col+1]==word[index])
        {
            visited[row][col]=1;

            bool ans3=solve(index+1,row,col+1,m,n,board,word,ds+board[row][col],visited);

            if(ans3==true){
                return true;
            }

            visited[row][col]=0;

        }

        //up
        if(row-1>=0 && visited[row-1][col]==0 && board[row-1][col]==word[index])
        {
            visited[row][col]=1;

            bool ans4=solve(index+1,row-1,col,m,n,board,word,ds+board[row][col],visited);

            if(ans4==true){
                return true;
            }

            visited[row][col]=0;

        }

        return false;

    }
};

int main()
{
    cout << "Word Break with Memoisation!" << endl;
    return 0;
}
