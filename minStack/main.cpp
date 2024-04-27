#include <iostream>
#include <map>
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

        if (MAP.find(val) == MAP.end())
            {
                MAP[val] = 1;
            }
        else
            {
                int increment = MAP[val];
                increment ++;
                MAP[val] = increment;
            }

        list[stackTop] = val;
        stackTop++;
    }

    // remove top of stack
    void pop()
    {
        int key = list[stackTop];
        MAP[key]--;
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

    void mapOutput()
    {
        map<int,int>::iterator mapIterator;
        for (mapIterator = MAP.begin(); mapIterator != MAP.end(); ++mapIterator)
            {
                cout << " Key: "<< mapIterator->first << " value: " << mapIterator->second << endl;
            }
    }

private:
    // to implement a stack we need to store data

    int *list; // pointer to the array that represents the stack
    int minimum; // min value of the stack
    int stackTop; // the position of the top of stack
    int maxStackSize;
    map<int,int> MAP;
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
    minStack->push(-3);
    minStack->push(-2);
    minStack->push(-2);


    cout << minStack->top() << endl;

    minStack->mapOutput();

    return 0;
}
