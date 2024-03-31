#include <iostream>

using namespace std;

/**
Starting at the root, traverse the tree adding one
*/

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
    int minDepth(TreeNode* root)
    {
        // base case 1
        if (root == nullptr)
            {
                return 0;
            }

        // base case 2
        if (root->left == nullptr && root->right == nullptr)
            {
                return 1;
            }

        // recursive case

        int left = INT_MAX;
        int right = INT_MAX;

        if (root->left != nullptr)
            {
                left = minDepth(root->left);
            }

        if (root->right != nullptr)
            {
                right = minDepth(root->right);
            }


        // base case final return
        return min(left,right) + 1;
    }
};

int main()
{
    cout << "Minimum Depth of a Binary tree!" << endl;

    cout << INT_MAX << endl;
    return 0;
}
