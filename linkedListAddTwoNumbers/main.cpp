#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;


//  Definition for singly-linked list.
struct ListNode {
    int val;             // Each Node will contain an integer, assumes int >= 0
    ListNode *next;     // holds address for next node, (where is the the address for the first node !!!!!)
    ListNode() : val(0), next(nullptr) {}   // ctor --> sets val(0), next(nullptr) --> set to
    ListNode(int x) : val(x), next(nullptr) {}      // ctor(1 param) --> sets val(x)
    ListNode(int x, ListNode *next) : val(x), next(next) {}     // ctor(2 params) --> sets val(x) and address of next (next)
 };

/*
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/*
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode *first;
        ListNode *second;
        first = l1;
        second = l2;
        ListNode* returnNode = new ListNode(0);
        long long int sumFirst = 0;
        long long int sumSecond = 0;

        long long int power = 0;

        // Compute sum of first linked list
        while (first != nullptr) {
            sumFirst += first->val * std::pow(10, power);
            first = first->next;
            power += 1;
        }

        power = 0;

        // Compute sum of second linked list
        while (second != nullptr) {
            sumSecond += second->val * std::pow(10, power);
            second = second->next;
            power += 1;
        }

        // End --> I now have the total value of the linked list
        long long int number = sumFirst + sumSecond;
        /*cout << number << endl;
        int reverse = 0;
        while (number !=0)
            {
                reverse = reverse * 10 + number % 10;
                number /= 10;
            }
   
        // End --> I now have the total value reversed
        long long int total = number;
        ListNode *beg, *newNode, *end;
        beg = nullptr;
        int r;
        if (total == 0 )
            {
                ListNode* node = new ListNode(0);
                return node;
            }

        while (total != 0)
            {
                r = total%10;
                newNode = new ListNode;
                newNode->val = r;
                newNode->next = nullptr;
                if (beg==nullptr)
                    {
                        beg = newNode;
                        end = newNode;
                    }
                else
                    {
                        end->next = newNode;
                        end = newNode;
                    }
                total /= 10;
            }
        return beg;
    }

};
*/



 void printNode(ListNode* node)
 {
    ListNode* temp;
    temp=node;
    while(temp!=nullptr)
        {
            cout << temp->val<< " Location: "<< temp->next << endl;
            temp = temp->next;
        }
 }

 int sumNode(ListNode* node)
 {
    ListNode *temp;
    temp = node;
    int sum =0;
    while (temp!=nullptr)
        {
            sum +=  temp->val;
            temp = temp->next;
        }
    return sum;
 }

ListNode* sumLinkedList(ListNode* node)
{
    ListNode *temp;
    temp = node;
    ListNode* returnNode = new ListNode(0);
    while (temp!=nullptr)
        {
            returnNode->val +=  temp->val;
            temp = temp->next;
        }
    return returnNode;
}

ListNode* sumLinkedLists(ListNode* l1, ListNode* l2)
{
    ListNode *first;
    ListNode *second;
    long long int power = 0;
    first = l1;
    second = l2;
    ListNode* returnNode = new ListNode(0);
    long long int sumFirst = 0;
    long long int sumSecond = 0;

    while (first != nullptr)
        {
            returnNode->val += first->val*pow(10,power);
            first = first->next;
            power +=1;
        }
    power = 0;
    while (second != nullptr)
        {
            returnNode->val += second->val*pow(10,power);
            second = second->next;
            power +=1;
        }

    // End --> I now have the total value of the linked list
    long long int number = returnNode->val;
    /*cout << number << endl;
    int reverse = 0;
    while (number !=0)
        {
            reverse = reverse * 10 + number % 10;
            number /= 10;
        }
*/
    // End --> I now have the total value reversed
    long long int total = number;
    ListNode *beg, *newNode, *end;
    beg = nullptr;
    cout << "Total" << total << endl;
    int r;
    if (total == 0 )
        {
            ListNode* node = new ListNode(0);
            return node;
        }

    while (total != 0)
        {
            r = total%10;
            newNode = new ListNode;
            newNode->val = r;
            newNode->next = nullptr;
            if (beg==nullptr)
                {
                    beg = newNode;
                    end = newNode;
                }
            else
                {
                    end->next = newNode;
                    end = newNode;
                }
            total /= 10;
        }
    cout << beg->val << endl;
    return beg;
}

ListNode* addTwoNodes(ListNode* l1, ListNode* l2)
{

    ListNode* first;
    ListNode* second;

    first = l1;
    second = l2;

    vector<int> summedValues;

    // just add 2 linked lists of same length
    int remainder = 0;
    while (first != nullptr || second != nullptr) 
    {
            int sum;
            if (first != nullptr && second != nullptr)
            {
                sum = first->val + second->val + remainder;
            }
            else if (first == nullptr) 
            {
                sum = 0 + second->val + remainder;
            }
            else 
            {
                sum = first->val + 0 + remainder;
            }
            remainder = 0;

            while (sum > 9) 
            {
                remainder +=1;
                sum -= 10;
                
            }
        summedValues.push_back(sum);

        if (first != nullptr)
            first = first->next;
        if (second != nullptr)
            second = second->next;
    }

    cout << "Remainder ==> " << remainder << endl;
    if (remainder > 0 ) 
    {
        summedValues.push_back(remainder);
    } 
    
    ListNode *beg, *newNode,*end;
    beg = nullptr;

    // Create the new linkedList
    for (int sum:summedValues) 
    {
        newNode = new ListNode(sum,nullptr);
        if (beg == nullptr) 
        {
            beg = newNode;
            end = newNode;   
        }
        else 
        {
            end->next = newNode;
            end = newNode;
        }
    }
    return beg;

}



ListNode* createLinkList(ListNode* l1)
{
     ListNode *first, *newNode, *last;
     int num;
     cout << "Enter a list of integers ending with -999."
     << endl;
     cin >> num;
     first = nullptr;
     while (num != -999)
     {
         newNode = new ListNode;
         newNode->val = num;
         newNode->next = nullptr;
         if (first == nullptr)
         {
            first = newNode;
            last = newNode;
         }
         else
         {
            last->next = newNode;
            last = newNode;
         }

         cin >> num;
     } //end while
     return first;
}

int main()
{
    /*
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    printNode(head);
    cout << sumNode(head) << endl;

    ListNode* node = sumLinkedList(head);
    cout << "Printing a linkedList val: " << node->val << endl;


    ListNode* head1 = new ListNode(2);
    head1->next = new ListNode(4);
    head1->next->next = new ListNode(3);

    ListNode* head2 = new ListNode(5);
    head2->next = new ListNode(6);
    head2->next->next = new ListNode(4);

    ListNode* sumNode = sumLinkedLists(head1,head2);
    cout <<"Printing the sum of 2 LinkedList: " << sumNode->val << endl;




    ListNode* newNode = sumLinkedLists(l1,l2);

    printNode(newNode);





    int number = 1234;
    int r;
    while (number != 0)
        {
            r = number%10;
            number/=10;
            cout << r << " ";
        }
    cout << "\n \n \n " << endl;
    ListNode* a = new ListNode(0);
    //a->next = new ListNode(4);
    //a->next->next = new ListNode(3);


    ListNode* b = new ListNode(0);
    //b->next = new ListNode(6);
    //b->next->next = new ListNode(4);

    ListNode* c = sumLinkedLists(a,b);

    printNode(c);

    ListNode* A = new ListNode(1);
    A->next = new ListNode(9);
    A->next->next = new ListNode(9);
    A->next->next->next = new ListNode(9);
    A->next->next->next->next = new ListNode(9);
    A->next->next->next->next->next = new ListNode(9);
    A->next->next->next->next->next->next = new ListNode(9);
    A->next->next->next->next->next->next->next = new ListNode(9);
    A->next->next->next->next->next->next->next->next = new ListNode(9);
    A->next->next->next->next->next->next->next->next->next = new ListNode(9);

    ListNode* B = new ListNode(9);

    ListNode* C = sumLinkedLists(A,B);
    printNode(C);
    int large = 110000000;
    cout << large << endl;
    */
    ListNode* head1 = new ListNode(2);
    head1->next = new ListNode(4);
    head1->next->next = new ListNode(3);

    ListNode* head2 = new ListNode(5);
    head2->next = new ListNode(6);
    head2->next->next = new ListNode(4);
    
    ListNode* node = addTwoNodes(head1, head2);
    printNode(node);
    cout << endl << endl;

    ListNode* l1 = new ListNode(9);
    l1->next = new ListNode(9);
    l1->next->next = new ListNode(9);
    l1->next->next->next = new ListNode(9);
    l1->next->next->next->next = new ListNode(9);
    l1->next->next->next->next->next = new ListNode(9);
    l1->next->next->next->next->next->next = new ListNode(9);

    ListNode* l2 = new ListNode(9);
    l2->next = new ListNode(9);
    l2->next->next = new ListNode(9);
    l2->next->next->next = new ListNode(9);
    ListNode* bigNode = addTwoNodes(l1,l2);
    printNode(bigNode);
    return 0;
}

/*
l1 =
[9]
l2 =
[1,9,9,9,9,9,9,9,9,9]

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
*/
