#include <iostream>

using namespace std;

/*
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
*/

class MyQueue {
    public:
        MyQueue() {
            // ctor
            // PC: sets the members.
            maxQueueSize = 100;
            queueFront = 0;
            queueRear = maxQueueSize - 1;
            count = 0;
            list = new int[maxQueueSize];
        }

        void push(int x) {
            if (count != maxQueueSize))
                {
                    queueRear = (queueRear + 1) % maxQueueSize;
                    // Use the mod operator to advance queueRear because the array is cirular
                    count++;
                    list[queueRear] = x;
                }
            else
                {
                    cout << "Cannot add to a full queue." << endl;
                }
        }

        int pop() {
            if (!empty())
                {
                    int front = list[queueFront];
                    count--;
                    queueFront = (queueFront+1) % maxQueueSize;
                    return front;
                }
            else
                {
                    cout << "Cannot delete from an empty queue." << endl;
                }
        }

        int peek() {
            assert(!empty()); // equivalent to !this.isEmptyQueue()
            return list[queueFront];
        }

        bool empty() {
            return (count == 0);
        }

    private:
        int maxQueueSize; // Max queue size
        int count; // stores number of elements in queue

        int queueFront; // points to first element of the queue

        int queueRear; // points to last element of the queue

        int *list; // pointer to the array that holds the queue elements
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
