#include <iostream>

using namespace std;

/**
Definition for singly-linked list.

 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Compare each passed node, and determine where it should be in the linked list
    // 1,4,3
    // 1,3,4
    ListNode* sortList(ListNode* head);
};



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
