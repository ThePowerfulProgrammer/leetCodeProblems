#include <iostream>

using namespace std;


//Definition for singly-linked list.
  struct ListNode {
      int val; // info
      ListNode *next; //  address

      // Ctor's
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
};

// solution
ListNode* Solution::mergeTwoLists(ListNode* list1, ListNode* list2)
{
    ListNode *lastSmall; // pointer to the last node of the merged list, last node
    ListNode *newHead; // pointer to the merged list, first node

    // check if either list is empty
    if (list1 == nullptr)
        {
            return list2;
        }
    else if (list2 == nullptr)
        {
            return list1;
        }
    // GREAT Neither list is empty
    else
        {
            // Compare the first pair of nodes, (x,y) x is a node from list1 and y is a node from list2
            // x < y
            if (list1->val < list2->val)
                {
                    newHead = list1; // newHead is now pointing to the same list as list1
                    list1 = list1->next; // advance list1 pointer
                    lastSmall = newHead; // initally set to newHead, just imagine if we had 1 element
                }
            // x > y
            else
                {
                    newHead = list2; // newHead is now pointing to the same list as list2
                    list2 = list2->next;
                    lastSmall = newHead; // newHead and lastSmall are pointing to the same linkedList
                }

            // Continue to search and compare pairs of the form  (x,y)
            while (list1 != nullptr && list2 != nullptr)
                {
                    if (list1->val < list2->val)
                        {
                            lastSmall->next = list1; // start connecting nodes
                            lastSmall = lastSmall->next; // advance lastSmall to the last node
                            list1 = list1->next; // advance list1
                        }
                    else
                        {
                            lastSmall->next = list2;
                            lastSmall = lastSmall->next;
                            list2 = list2->next; // advance list2
                        }
                }

            if (list1 == nullptr) // list1 is exhausted first
                {
                    lastSmall->next = list2; // point to rest of list2
                }
            else
                {
                    lastSmall->next = list1; // list2 is exhausted first, point to rest of list1
                }

            return newHead;
        }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
