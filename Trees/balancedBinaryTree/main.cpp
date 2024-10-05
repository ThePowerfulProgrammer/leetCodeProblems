#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;


/**
    The problem is that we are trying to determin if the height of the left tree and
    right tree differ by 0 or 1 and anv value is incorrect.


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
    bool isBalanced(TreeNode* root) {
        return dfs(root)[0] == 1;
    }

private:
    vector<int> dfs(TreeNode *root)
    {
        if (root == nullptr)
            {
                return {1,0};
            }

        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);

        bool balanced = (left[0] == 1) && (right[0] == 1) && abs(left[1] - right[1]) <= 1;
        int height = 1 + max(left[1] + right[1])'

        return {balanced ? 1:0, height};

    }
};


int main()
{
    cout << "Is this b tree height balanced?!" << endl;
    return 0;
}
