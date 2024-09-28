#include <iostream>
#include <algorithm>

using namespace std;


 struct TreeNode
 {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr)
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    int maxDepth(TreeNode* root)
    {
        if (root == nullptr)
            {
                return 0;
            }
        return 1+std::max(maxDepth(root->left), maxDepth(root->right));

    }


};


int main()
{
    cout << "Find the max depth of a B-Tree!" << endl;
    return 0;
}
