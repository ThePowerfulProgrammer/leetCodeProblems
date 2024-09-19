#include <iostream>
#include <climits>

using namespace std;

struct Node {
    int data;
    Node *first; // pointer to the firstNode in the linkedList
    Node *last; // pointer to the last node in the linkedList == top of the stack

    Node()
    {
        data = 0;
        first = nullptr;
        last = nullptr;
    }

    Node(int val)
    {
        data = val;
        first = nullptr;
        last = nullptr;
    }
};



class MinStack {
public:
    MinStack() :
        count(0),
        minimum(INT_MAX),
        head(nullptr), // list is initially empty
        tail(nullptr)
    {
    }

    void push(int val)
    {
        // create new node and add it to stack
        if (head == nullptr) // adding a newnode means that node must be the first node
            {
                Node* newNode = new Node(val);
                if (val < minimum)
                    {
                        minimum = val;
                    }

                head = newNode;
                tail = head;
                cout << "added first node " << head->data <<  endl;
                cout << "added first node tail: " << tail->data <<  endl;

            }
        else
            {
                Node *newNode = new Node(val);

                if (val < minimum)
                    {
                        minimum = val;
                    }

                // traverse linked list to find last node
                /*Node *temp = new Node();
                temp = head;
                while (temp->last)
                    {
                        temp = temp->next;
                    }
                temp->last = newNode;
                tail = newNode;*/

                tail->last = newNode;
                tail = newNode;

            }
    }

    void pop()
    {
        if (head != nullptr)
            {
                if (head != tail)
                    {
                        Node *tempNode = new Node();
                        tempNode = head;
                        while (tempNode->last->last != nullptr)
                            {
                                tempNode = tempNode->last;
                            }
                        tail = tempNode;
                        tempNode = tempNode->last;
                        delete tempNode;
                        tempNode = nullptr;
                    }
                else
                    {
                        cout << "head  == tail \n";
                        delete head;
                        head = nullptr;
                    }

            }
        else
            {
                return;
            }
    }

    int top()
    {
        if (head)
            {
                cout << "Runnin \n";
                return tail->data;
            }
        return 0;

    }

    int getMin()
    {
        return minimum;
    }

private:
    int count;
    int minimum;
    Node *head;
    Node *tail;

};


int main()
{
    cout << "Design a stack class that supports push,pop, top and getMin operations!" << endl;

    MinStack mystack;
    mystack.push(1);
    mystack.push(3);
    mystack.push(2);
    mystack.push(-1);
    mystack.push(0);

    mystack.pop();


    cout << mystack.top() << endl;
    cout << mystack.getMin() << endl;
    return 0;
}










