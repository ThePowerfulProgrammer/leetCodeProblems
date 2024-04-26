#include <iostream>

using namespace std;

// I assumed this is a stack of integers
class MinStack {
public:
    // default ctor
    MinStack()
    {
        minimum = INT_MAX; // let it be the largest int we are allowed to refer to
        stackTop = 0;
        maxStackSize = 30000;
        list = new int[maxStackSize];
    }

    // add to top of stack
    void push(int val)
    {
        if (val < minimum)
            {
                minimum = val;
            }
        list[stackTop] = val;
        stackTop++;
    }

    // remove top of stack
    void pop()
    {
        stackTop -=1;
    }

    // return top of stack
    int top()
    {
        return list[stackTop-1];
    }

    // retrieve the minimum element from the stack
    int getMin()
    {
        return minimum;
    }

private:
    // to implement a stack we need to store data

    int *list; // pointer to the array that represents the stack
    int minimum; // min value of the stack
    int stackTop; // the position of the top of stack
    int maxStackSize;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{
    cout << "Create a MinStack!" << endl;

    MinStack *minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);

    cout << minStack->top();

    return 0;
}
