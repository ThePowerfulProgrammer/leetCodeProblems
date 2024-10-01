#include <iostream>

using namespace std;


class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root)
    {
        if (root == nullptr)
            {
                return 0;
            }

        int lHeight = height(root->left);
        int rHeight = height(root->right);

        int lDiameter = diameterOfBinaryTree(root->left);
        int rDiamter = diameterOfBinaryTree(root->right);

        return max({lHeight + rHeight + 1, lDiamter, rDiamter});
    }

private:
    int height(TreeNode *node)
    {
        if (node == nullptr)
            {
                return 0;
            }

        return 1 + max(height(node->left),
                       height(node->right));
    }

};


int main()
{
    cout << "Binary Tree Diameter?!" << endl;
    return 0;
}
