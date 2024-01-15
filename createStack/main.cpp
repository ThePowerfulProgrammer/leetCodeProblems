#include <iostream>

using namespace std;


class MyStack {
    public:
        MyStack() {
            // ctor
            // PC: sets the values of member variables.
            maxStackSize = 100; // max number of elements in the stack
            stackTop = 0; // top value of stack
            list = new int[maxStackSize]; // list is of max size 100 --> holds 100 elements
        }

        void push(int x) {
            // adds elements to the stack, inserted at the top

            if (stackTop == maxStackSize)
                {
                    cout << "Stack is full" << endl;
                }
            else
                {
                    list[stackTop] = x;
                    stackTop++;
                }
        }

        int pop() {
            // Pop, means to remove top of stack
            // all pop calls are valid
            // no need for error checks and validation
            int popped = list[stackTop-1]; // grab element at position
            stackTop--;
            return popped;
        }

        int top() {
            // all calls are valid
            return list[stackTop-1];
        }

        bool empty() {
            return (stackTop == 0);
        }
    private:
        int maxStackSize; // holds max size of stack
        int stackTop; // A Stack is a stack
        int *list; // pointer to the array that holds the values of the stack
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */


int main()
{
    cout << "i am so excited!" << endl;
    return 0;
}
