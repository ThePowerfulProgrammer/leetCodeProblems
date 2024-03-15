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


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    vector<string> binaryTreePaths(TreeNode* root, vector<string> path, vector<string> paths)
    {
        path.push_back(root->val);

        if (root->left==nullptr && root->right==nullptr)
            {

            }
        else
            {
                binaryTreePaths(root->left,path,paths);
                path.pop_back();
            }
    }
    vector<string> binaryTreePaths(TreeNode* root)
    {
        if (root==nullptr) // we have nothing therefore we have everything. CASE 0
            {
                return {};
            }
        if (root->left == nullptr && root->right == nullptr) // if we have the root and nothing else, we have everything. CASE 1
            {
                string path = to_string(root->val);
                return {path};
            }
        // now we return our helper function

        vector<string> path = {};
        vector<string> paths = {};
        return binaryTreePaths(root,path, paths);
    }
};



int main()
{
    cout << "Binary tree paths using recursion!" << endl;
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);



    return 0;
}
