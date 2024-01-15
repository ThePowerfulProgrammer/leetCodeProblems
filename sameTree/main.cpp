#include <iostream>
#include <vector>
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

    PA -> PD
    The problem involves determining if the elements in 2 trees match not only in value but also in position

    Solution:
    Traverse each tree using the same traversal method, if the 2 trees are identical then the resultant traversal method will produce the same result

    Create 2 private member vectors, 1 for each tree.
    Add all nodes one by one using traversal method.
    If the vectors are equal return true else return false
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

};

class Solution {
public:

    void pTraversal(TreeNode* p) // using inorder traversal on p
    {
        if (p != nullptr)
            {
                if (p->left == nullptr || p->right == nullptr)
                    {
                        //cout << "nullptr" << endl;
                        pNodes.push_back(0);
                    }
                pTraversal(p->left);
                pNodes.push_back(p->val);
                pTraversal(p->right);
            }
    }

    void qTraversal(TreeNode* q) // using inorder traversal on q
    {
        if (q != nullptr)
            {
                if (q->left == nullptr || q->right == nullptr)
                    {
                        //cout << "nullptr" << endl;
                        qNodes.push_back(0);
                    }

                qTraversal(q->left);
                qNodes.push_back(q->val);
                qTraversal(q->right);
            }
    }

    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        pTraversal(p);
        qTraversal(q);
        return pNodes == qNodes;

    }


private:
    vector<int> pNodes;
    vector<int> qNodes;
};




int main()
{
    cout << "Determine if 2 Trees are the same!" << endl;
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(1);

    TreeNode* q = new TreeNode(1);
    q->left = nullptr;
    q->right =  new TreeNode(1);

    Solution s1;
    cout << s1.isSameTree(p,q) << endl;

    return 0;
}
