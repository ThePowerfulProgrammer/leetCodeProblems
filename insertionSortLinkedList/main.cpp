#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

// Traverses a linked list and returns all values
void traverseLinkedList(ListNode *head)
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
    // returns a linkedlist
/*
    Create two linked lists: one for the sorted part and one for the unsorted part.
    Initialize the sorted list with the first element from the unsorted list.
    Traverse through the unsorted list, removing elements one by one and inserting them into the correct position in the sorted list.
    Repeat step 3 until the unsorted list becomes empty.
*/
    ListNode* insertionSortList(ListNode* head)
    {
        ListNode* sortedList = new ListNode(head->val,nullptr);

        head = head->next; // node used for traversal of the unsorted linked list

        while (head != nullptr)
            {
                ListNode* newNode = new ListNode(head->val,nullptr);

                // determine if left insertion or right insertion
                if (newNode->val <= sortedList->val) // left insertion
                    {
                        newNode->next = sortedList;
                        sortedList = newNode;
                    }
                else // right insertion: 2 possible cases
                    {
                        ListNode* current = sortedList;
                        ListNode* preCurrent = nullptr;
                        bool found = false;

                        while (current != nullptr && !found) // 1->2->3->4->nullptr: read in 6
                            {
                                if (current->val >= newNode->val)
                                    {
                                        found = true;
                                    }
                                else
                                    {
                                        preCurrent = current;
                                        current = current->next;
                                    }
                            }
                        preCurrent->next = newNode;
                        newNode->next = current;
                    }
                head = head->next;
            }

        return sortedList;

    }
};



int main()
{
    ListNode* head = new ListNode(4); // 4->nullptr
    head->next = new ListNode(3,nullptr); // 4->3->nullptr
    head->next->next = new ListNode(2,nullptr); // 4->3->2->nullptr
    head->next->next->next = new ListNode(1,nullptr); // 4->3->2->1->nullptr
    head->next->next->next->next = new ListNode(6,nullptr); // 4->3->2->1->6->nullptr
    head->next->next->next->next->next = new ListNode(0,nullptr); // 4->3->2->1->6->0->nullptr
    head->next->next->next->next->next->next = new ListNode(5,nullptr); // 4->3->2->1->6->0->5->nullptr

    Solution s1;
    traverseLinkedList(s1.insertionSortList(head));

    return 0;
}
