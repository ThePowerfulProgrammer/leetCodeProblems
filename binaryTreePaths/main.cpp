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


void treeTraversal(TreeNode *root)
{
    if (root != nullptr)
        {
            cout << root->val << endl;
            treeTraversal(root->left);
            treeTraversal(root->right);
        }
}

void rootToLeafPaths(TreeNode *root, string nodes)
{
    nodes += to_string(root->val);
    if (root->left == nullptr && root->right == nullptr)
        {
            // found a leaf
            cout << nodes << endl;
        }
    else
        {
            rootToLeafPaths(root->left,nodes);
            rootToLeafPaths(root->right, nodes);
        }
}

int main()
{
    cout << "Binary tree paths using recursion!" << endl;

    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(3);
    root->left->right =  new TreeNode(4);
    root->left->left = new TreeNode(1);
    root->left->left->right = new TreeNode(2);
    root->right = new TreeNode(6);


    Solution s1;

    treeTraversal(root);
    cout << endl << endl;
    string nodes = "";
    rootToLeafPaths(root, nodes);
    return 0;
}
