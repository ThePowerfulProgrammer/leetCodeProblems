#include <iostream>
#include <climits>
#include <stack>

using namespace std;

struct Node {
    int data;
    Node *first; // pointer to the firstNode in the linkedList

    Node()
    {
        data = 0;
        first = nullptr;
    }

    Node(int val)
    {
        data = val;
        first = nullptr;
    }
};



class MinStack {
public:
    MinStack() :
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


                minimumStack.push(val);


                head = newNode;
                tail = head;
                //cout << "added first node " << head->data <<  endl;
                //cout << "added first node tail: " << tail->data <<  endl;

            }
        else
            {
                Node *newNode = new Node(val);

                if (val < minimumStack.top() )
                    {
                        cout << "pushed: " << val << endl;
                        minimumStack.push(val);
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

                tail->first = newNode;
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
                        while (tempNode->first->first != nullptr)
                            {
                                tempNode = tempNode->first;
                            }

                        tail = tempNode;

                        //cout << "temp->data before moving forward: " << tempNode->data << endl;
                        tempNode = tempNode->first;
                        //cout << "temp->data after moving forward: " << tempNode->data << endl;

                        if ( tempNode->data == getMin())
                            {
                                //cout << "tempnode->data: " << tempNode->data << " getMin() " << getMin() << endl;
                                minimumStack.pop();

                            }

                        delete tempNode;
                        tempNode = nullptr;

                        tail->first = nullptr;

                    }
                else
                    {
                        cout << "head  == tail \n";

                        minimumStack.pop();
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
                //cout << "Runnin \n";
                return tail->data;
            }
        return 0;

    }

    int getMin()
    {
        return minimumStack.top();
    }

private:
    Node *head;
    Node *tail;
    std::stack<int> minimumStack;
};


int main()
{
    cout << "Design a stack class that supports push,pop, top and getMin operations!" << endl;
    cout << "5->0->2->4" << endl ;
    MinStack mystack;
    mystack.push(5);
    mystack.push(0);
    mystack.push(2);
    mystack.push(4);
    cout << mystack.getMin() << endl;
    mystack.pop(); // needs to consider popping the node with the current minimum value
    cout << mystack.getMin() << endl;
    mystack.pop();
    cout << mystack.getMin() << endl;

    mystack.push(-1);
    cout << mystack.getMin() << endl;
    cout << mystack.top() << endl;
    return 0;
}










