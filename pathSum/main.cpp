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
bool hasPathSum(TreeNode * root, int targetSum)
{
    // seed code
    vector<int> root_to_leaf; // all root-to-lead paths

    // recursive solutions to build all paths

    return createPaths(root,root_to_leaf,targetSum);
}


bool createPaths(TreeNode* root, vector<int>& root_to_leaf, int targetSum)
{
    if (root == nullptr)
        {
            return false;
        }

    root_to_leaf.push_back(root->val);

    if (root->left == nullptr && root->right == nullptr)
        {
            // found a root-lead path now process
            return checkPath(paths,targetSum);
        }
    else
        {
            // populate paths with nodes
            createPaths(root_to_leaf->left,paths,targetSum);
            createPaths(root_to_leaf->right,paths,targetSum);
        }

    root_to_leaf.pop_back();
}

bool checkPath(vector<int> & root_to_leaf, int targetSum)
{
    int sum = 0;

    for (const int &i: root_to_leaf)
        {
            sum += i;
        }
    return sum == targetSum;
}



class Solution {
public:
    void hasPathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        printPaths(root, path, targetSum);
    }

    void printPaths(TreeNode* root, vector<int>& path, int targetSum) {
        if (root == nullptr) {
            return;
        }

        // Append the current node's value to the path
        path.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr) {
            // Leaf node: Print the path
            printPath(path,targetSum);
        } else {
            // Recurse on left and right subtrees
            printPaths(root->left, path,targetSum);
            printPaths(root->right, path, targetSum);
        }

        // Backtrack: Remove the last element from the path
        path.pop_back();
    }



private:
    void printPath(const vector<int>& path, int targetSum) {
        for (const int &j: path) {
            cout << j << "->";
        }
        cout << endl;

        int sum = 0;
        for (int i = 0; i < path.size(); ++i) {
            sum += path[i];
        }

        if (sum == targetSum) {
            cout << sum << endl;
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
    s1.hasPathSum(root,23);
    return 0;
}
