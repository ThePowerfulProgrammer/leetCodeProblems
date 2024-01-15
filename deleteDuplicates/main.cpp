#include <iostream>

using namespace std;

// Definition for singly-linked list.
 struct ListNode
 {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 void traverseLinkedList(ListNode* head)
 {
     ListNode* temp = head;
    while (temp != nullptr)
        {
            cout << temp->val << " " ;
            temp = temp->next;
        }
    cout << endl;
 }

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (head == nullptr) {return nullptr;}

        ListNode* newList = new ListNode(head->val); // insert first node
        ListNode* current = newList;
        ListNode* pre = head;
        ListNode* post = (pre != nullptr) ? pre->next : nullptr;

        while (pre != nullptr)
            {

                if (post != nullptr && pre->val != post->val)
                {
                    ListNode* newNode = new ListNode(post->val);
                    current->next = newNode;
                    current = newNode;
                }
                pre = post;
                post = (post != nullptr) ? post->next: post;
            }
        return newList;
    }
};

int main()
{
    ListNode* head = new ListNode(1); // 1->nullptr
    head->next = new ListNode(1,nullptr); // 1->1->nullptr
    head->next->next = new ListNode(2,nullptr); // 1->1->2->nullptr
    head->next->next->next = new ListNode(2,nullptr); // 1->1->2->1->nullptr
    head->next->next->next->next = new ListNode(3,nullptr); // 1->1->2->2->3->nullptr
    head->next->next->next->next->next = new ListNode(3,nullptr); // 1->1->2->2->3->3->nullptr

    Solution s1;
    ListNode* l1 = s1.deleteDuplicates(head);
    traverseLinkedList(l1);

    return 0;
}
