#include <iostream>
#include <vector>


using namespace std;

 struct TreeNode
 {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}



};

/*
Check root
Check left
Check right
*/

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        if (root == nullptr && subRoot == nullptr)
            {
                return true;
            }

        if (!subRoot)
            {
                return true;
            }

        if (root == nullptr || subRoot == nullptr)
            {
                return false;
            }

        return isSameTree(root, subRoot) || isSameTree(root->left, subRoot) || isSameTree(root->right, subRoot);
    }

private:


    bool isSameTree(TreeNode *root, TreeNode *subRoot)
    {
        if (!root && !subRoot)
            {
                return true;
            }


        if (root && subRoot && root->val == subRoot->val)
        {
            return sameTree(root->left, subRoot->left) && sameTree(root->right, subRoot->right);
        }
        return false;


    }


    bool inOrderCheck(TreeNode *l, TreeNode *r)
    {
        if (l != nullptr && r != nullptr)
            {
                if (l->val == r->val)
                    {
                        return inOrderCheck(l->left, r->left) && inOrderCheck(l->right, r->right);
                    }
                else
                    {
                        cout << l->val << " != " << r->val << endl;
                        return false;
                    }

            }
        else if (l == nullptr && r == nullptr)
            {
                return true;
            }
        else
            {
                return false;
            }
    }

    void inOrderTraversal(TreeNode *root, TreeNode *subRoot)
    {
        if (root == nullptr)
            {
                return;
            }

        inOrderTraversal(root->left, subRoot);

        result = isSubtree(root, subRoot);
        if (result)
            {
                return;
            }

        inOrderTraversal(root->right, subRoot);



    }

    bool result = false;

};



int main()
{
    cout << "simply run isSameTree once you have an initial root match!" << endl;
    return 0;
}
