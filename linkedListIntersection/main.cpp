#include <iostream>
#include <vector>
using namespace std;



struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        // traverse headA storing each address
        vector<ListNode*> addressA;

        while (headA != nullptr)
            {
                addressA.push_back(headA);
                headA = headA->next;
            }

        // traverse headB storing each address
        vector<ListNode*> addressB;

        while (headB != nullptr)
            {
                addressB.push_back(headB);
                headB = headB->next;
            }

        // Find the intersection point
        ListNode *intersection = nullptr;
        for (int i = 0; i < addressA.size(); i++)
        {
            for (int j = 0; j < addressB.size(); j++)
            {
                if (addressA[i] == addressB[j])
                {
                    intersection = addressA[i];
                    cout << intersection << endl;
                    break;
                }
            }

            if (intersection != nullptr)
            {
                break;
            }
        }
        return intersection;
    }
};

int main()
{
    cout << "Linked List Intersection " << endl;

    ListNode *head = new ListNode(2);
    head->next = new ListNode(3);
    head->next->next = new ListNode(4);

    vector<ListNode*> addresses;


    ListNode *temp = head;

    while (temp != nullptr )
        {
            cout << temp << " -> " << temp->val << " Address of value "<<  &temp->val << endl;
            addresses.push_back(temp);
            temp = temp->next;
        }

    for (auto node: addresses)
        {
            cout << node << " ";
        }


    return 0;
}
