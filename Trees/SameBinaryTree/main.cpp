#include <iostream>

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

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        return inOrderCheck(p, q);
    }

private:

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
};



int main()
{
    cout << "Are these just the same tree?!" << endl;
    return 0;
}
