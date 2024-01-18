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
    TreeNode* createTree(vector<int>& nums, int left, int right)
    {
        if (left<=right)
            {
                int mid = low+(high-low)/2;
                TreeNode* node = new TreeNode(nums[mid]);
                node->left=solve(nums,left,mid-1);
                mode->right=solve(nums,mid+1,right);
                return root;
            }
        return nullptr;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        return createTree(nums,0,nums.size()-1);
    }
};


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
