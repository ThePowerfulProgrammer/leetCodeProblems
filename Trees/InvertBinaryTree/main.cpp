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

 struct TreeNode
 {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr)
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    /*
        Traverse left
        Visit node
        Traverse right
    */
    void inorderTraversal()
    {
        if (this != nullptr)
            {
                inorderTraversal(this->left);
                cout << this->val << endl;
                inorderTraversal(this->right);
            }

    }

    /*
        Visit node
        Traverse left
        Traverse right
    */

    void preorderTraversal()
    {
        if (this != nullptr)
            {
                cout << this->val << endl;
                preorderTraversal(this->left);
                preorderTraversal(this->right);
            }

    }

    /*
        Traverse left
        Traverse right
        Visit node
    */
    void postorder()
    {
        if (this != nullptr)
        {
            postorder(this->left);
            postorder(this->right);
            cout << this->val << endl;
        }


    }

 };


class Solution {
public:
    TreeNode* invertTree(TreeNode* root)
    {
        TreeNode *tempLeft = root->left;
        TreeNode *tempRight = root->right;


        root->right = tempLeft;
        root->left = tempRight;

        return root;
    }


};


int main()
{
    cout << "Invert Binary Tree!" << endl;

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->left =  new TreeNode()
    root->right = new TreeNode(6);

    return 0;
}
