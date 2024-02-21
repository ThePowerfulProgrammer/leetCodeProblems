#include <iostream>

using namespace std;

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

 A binary tree's maximum depth is the number of nodes along the
 longest path from the root node down to the farthest leaf node.
 */


class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        else {
             return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
        }
    }
};


int main()
{
    cout << "MAximum depth of binary tree!" << endl;
    return 0;
}
