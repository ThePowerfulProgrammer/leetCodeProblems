#include <iostream>
#include <vector>
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

    What is PreOrder Traversal?
    --> In a preorder traversal, the binary tree is traversed as follows:
    1. Visit the node.
    2. Traverse the left subtree.
    3. Traverse the right subtree.

    Can solve using recursion
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

};



class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        if (root != nullptr)
            {
                nodes.push_back(root->val);
                preorderTraversal(root->left);
                preorderTraversal(root->right);
            }
        return nodes;
    }
private:
    vector<int> nodes;
};

int main()
{
    cout << "PreOrder Traversal!" << endl;
    return 0;
}
