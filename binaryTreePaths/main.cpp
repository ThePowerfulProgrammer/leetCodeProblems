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

    void binaryTreePaths(TreeNode* root, vector<string> &path, vector<string> &paths)
    {
        if (root == nullptr) // base case
            {
                return;
            }

        path.push_back(to_string(root->val));

        if (root->left == nullptr && root->right == nullptr)
            {
                cout << "in if" << endl;
                string temp = "";
                for (const auto s: path)
                    {
                        temp += s;
                        temp += "->";
                    }
                temp.pop_back();
                temp.pop_back();

                cout << "path: " << temp << endl;

                paths.push_back(temp);
            }

        binaryTreePaths(root->left,path,paths);
        binaryTreePaths(root->right,path,paths);
        path.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root)
    {

        binaryTreePaths(root,path,paths);
        cout << paths.size() << endl;
        return paths;
    }

private:
    vector<string> paths = {}; // root-to-leaf paths
    vector<string> path = {}; // nodes in the path
};



int main()
{
    cout << "Binary tree paths using recursion!" << endl;
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(6);


    Solution s1;

    for (const auto p: s1.binaryTreePaths(root))
        {
            cout << p << endl;
        }


    return 0;
}
