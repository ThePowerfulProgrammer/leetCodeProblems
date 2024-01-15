#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for a tree node.
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
                pTraversal(p->left);
                pNodes.push_back(p->val);
                pTraversal(p->right);
            }
    }

    void qTraversal(TreeNode* q) // using inorder traversal on q
    {
        if (q != nullptr)
            {
                qTraversal(q->left);
                qNodes.push_back(q->val);
                qTraversal(q->right);
            }
    }
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        pTraversal(p);
        qTraversal(q);
        for (int i:pNodes)
        {
            cout << i << endl;
        }
        for (int j:qNodes)
        {
            cout << j << endl;
        }
        return pNodes == qNodes;

    }
private:
    vector<int> pNodes;
    vector<int> qNodes;
};

int main()
{
    cout << "PostOrder Traversal!" << endl;
    return 0;
}
