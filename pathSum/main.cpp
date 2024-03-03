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




class Solution {
public:
    void printPaths(TreeNode* root, vector<int>& path) {
        if (root == nullptr) {
            return;
        }

        // Append the current node's value to the path
        path.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr) {
            // Leaf node: Print the path
            printPath(path);
        } else {
            // Recurse on left and right subtrees
            printPaths(root->left, path);
            printPaths(root->right, path);
        }

        // Backtrack: Remove the last element from the path
        path.pop_back();
    }

    void hasPathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        printPaths(root, path);
    }

private:
    void printPath(const vector<int>& path) {
        for (int i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i < path.size() - 1) {
                cout << " -> ";
            }
        }
        cout << endl;
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
    s1.hasPathSum(root,21);
    return 0;
}
