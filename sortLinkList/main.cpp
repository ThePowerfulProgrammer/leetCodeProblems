#include <iostream>

using namespace std;


//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}



};

class Solution {
public:
    // divide the linkedlist into 2 sublists
    void divideList(ListNode* l1,ListNode* &l2)
    {

        ListNode* middle; // middle set initally to first node
        ListNode* current; // current set initally set to third node, middle and current attempt to maintain a distance of 2 nodes

        if (l1 == nullptr)  // list is empty
            {
                l2 = nullptr;
            }
        else if (l1->next == nullptr)   // list has one lone  node
            {
                l2 = nullptr;
            }
        else
            {
                middle = l1;
                current = l1->next;

                if (current != nullptr) // only possible if list has more than 1 node
                    {
                        current = current->next; // current is now 2 ahead of middle
                    }
                while (current != nullptr )
                    {
                        middle = middle->next;
                        current = current->next;
                        if (current != nullptr)
                            {
                                current = current->next;
                            }
                    }
                    l2 = middle->next;
                    middle->next = nullptr;
            }
    }

    // merge both lists
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode *lastSmall; // pointer to the last node of the merged list
        ListNode *newHead; // pointer to the merged list

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
                        lastSmall = newHead;
                    }

                // Continue to search and compare pairs of the form  (x,y)
                while (list1 != nullptr && list2 != nullptr)
                    {
                        if (list1->val < list2->val)
                            {
                                lastSmall->next = list1; // start connecting nodes
                                lastSmall = lastSmall->next; // advance lastSmall to the last node
                                list1 = list1->next;
                            }
                        else
                            {
                                lastSmall->next = list2;
                                lastSmall = lastSmall->next;
                                list2 = list2->next;
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


    // recursively divide and merge until we have completed all
    void recMergeSort(ListNode* &head)
    {
        ListNode* otherHead;

        if (head != nullptr) // list must not be empty
            {
                if (head->next != nullptr) // more than one node?
                    {
                        divideList(head,otherHead);
                        recMergeSort(head);
                        recMergeSort(otherHead);
                        head = mergeTwoLists(head,otherHead);
                    }
            }
    }


    // call recMergeSort on head
    ListNode* sortList(ListNode* head) {
            if (head == nullptr)
                {
                    return head;
                }
            recMergeSort(head);
            return head;
    }

};

 void printNode(ListNode* node)
 {
    ListNode* temp;
    temp=node;
    while(temp!=nullptr)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
    cout << endl << endl;
 }

int main()
{
    ListNode* start = new ListNode(4);
    start->next = new ListNode(2);
    start->next->next = new ListNode(1);
    start->next->next->next =  new ListNode(3);
    printNode(start);

    Solution sol1;
    start = sol1.sortList(start);
    printNode(start);


    return 0;
}
