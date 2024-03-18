#include <iostream>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };



class Solution {
public:

    bool isSymmetric(TreeNode *leftNode, TreeNode *rightNode)
    {
        // base case
        if (leftNode == nullptr && rightNode == nullptr)
            {
                return true; // both exist as nullptr
            }

        // base case: Leads to Divorce
        if (leftNode == nullptr || rightNode == nullptr)
            {
                return false; // we have one as nothing and one as something, therefore false
            }


        if (leftNode->val != rightNode->val)
            {
                return false;

            }
        // recursive case
        return (isSymmetric(leftNode->left,rightNode->right) && isSymmetric(leftNode->right,rightNode->left));
    }

    bool isSymmetric(TreeNode* root)
    {
        if (root==nullptr)
            {
                return true; // if we have nothing, therefore we have everything
            }

        return isSymmetric(root->left,root->right); // evaluates to true or false
    }
};


int main()
{
    cout << "Symmmetric Binary Tree using recursion!" << endl;
    return 0;
}
