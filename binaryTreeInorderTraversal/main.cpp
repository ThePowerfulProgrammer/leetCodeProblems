#include <iostream>
#include <vector>
#include <stack>

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

    What is inorder Traversal?
    --> In an inorder traversal, the binary tree is traversed as follows:
    1. Traverse the left subtree.
    2. Visit the node.
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
    // recursive
    vector<int> inorderTraversal(TreeNode* root)
    {
        if (root != nullptr)
            {
                inorderTraversal(root->left);
                nodes.push_back(root->val);
                inorderTraversal(root->right);
            }

        return nodes;
    }
    // iterative
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> nodes;
        stack<TreeNode*> Stack;
        TreeNode* current = root;

        while (current != nullptr || !Stack.empty())
        {
            while (current != nullptr)
            {
                Stack.push(current);
                current = current->left;
            }
            current = Stack.top();
            Stack.pop();
            nodes.push_back(current->val);
            current = current->right;
        }
        return nodes;
    }

private:
    vector<int> nodes;
};

int main()
{
    cout << "TreeNode + inorderTraversal!" << endl;


    return 0;
}
