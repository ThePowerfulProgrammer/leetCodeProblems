#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


class Solution
{
    public:
        vector<string> binaryTreePaths(TreeNode* root)
        {
            return {};
        }



    private:

};


int main()
{
    cout << "Binary tree paths using recursion!" << endl;

    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(1);
    root->right = new TreeNode(6);

    Solution s1;
    s1.binaryTreeTraversal(root);

    return 0;
}
