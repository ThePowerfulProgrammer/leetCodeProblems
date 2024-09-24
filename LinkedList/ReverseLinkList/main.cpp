#include <iostream>
#include <vector>

using namespace std;

/**
    Simply approach:
    Iterate through list -> Collect pointers to next node in a vector
    Iterate from the end of that vector and create new nodes
*/


// Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        vector<int> values;
        vector<ListNode*> pointers;

        ListNode *temp = head;

        while (temp != nullptr)
            {
                pointers.push_back(temp);
                values.push_back(temp->val);
                temp = temp->next;
            }

            /*
        for (int i = 0; i < values.size() ;i++)
            {
                cout << values[i] << " " << pointers[i] << endl;
            }

        cout << endl << endl;
*/

        ListNode *reversedHead = nullptr;
        ListNode *last = nullptr;

        for (int i = pointers.size() - 1; i >= 0 ; i--)
            {
                //cout << values[i] << " " << pointers[i-1] << endl;
                ListNode *newNode = new ListNode(values[i]);
                if (reversedHead == nullptr && last == nullptr)
                    {
                        reversedHead = newNode;
                        last = newNode;
                    }
                else
                    {
                        last->next = newNode;
                        last =  newNode;
                    }
            }
        cout << endl << endl;

        ListNode *traversalNode = reversedHead;
        while (traversalNode != nullptr) {
            cout << traversalNode << " " << traversalNode->val << " " << traversalNode->next << " --> ";
            traversalNode = traversalNode->next;
        }

        cout << "null" << endl;

        return reversedHead;


    }
};

int main()
{
    cout << "Reverse a Singly linked List!" << endl;
    Solution s1;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next =  new ListNode(3);

    s1.reverseList(head);
    return 0;
}
