#include <iostream>
#include <vector>
using namespace std;



// Definition for a binary tree node.

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };



 // Determines if any nodes in a root-> leaf path adds to targetSum : true else: false
/**
I need to Psuedo code it :^)


*/

 class Solution
 {
public:
    hasPathSum(TreeNode* root, int targetSum)
    {


    }

private:

 };





int main()
{
    cout << "PathSum!" << endl;

    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(8);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(2);

    Solution s1;
    s1.hasPathSum(root,23);
    return 0;
}
