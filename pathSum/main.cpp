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

class Solution{
    public:
        int hasPathSum(TreeNode* root, int targetSum)
        {
            TreeNode* newNode = root;
            int rootToLeafSum = 0;

            if (newNode == nullptr)
                {
                    return 0;
                }
            return createPath(newNode,rootToLeafSum);
        }

    private:
        int createPath(TreeNode* root, int &initialValue )
        {
            initialValue += root->val;

            if (root->left == nullptr && root->right == nullptr)
                {
                    cout << "process root-to-leaf path" << endl;
                    return initialValue;
                }
            else
                {
                    return createPath(root->left,initialValue);
                    return createPath(root->right,initialValue);
                }


        }

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
    cout << s1.hasPathSum(root,23);
    return 0;
}
