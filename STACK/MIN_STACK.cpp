#include <stack>

class MinStack {
private:
    std::stack<int> mainStack;  // Stack to hold all values
    std::stack<int> minStack;    // Stack to hold the minimum values

public:
    // Constructor
    MinStack() {
        // The stacks are automatically initialized
    }
    
    // Push a new value onto the stack
    void push(int val) {
        mainStack.push(val);  // Push value onto the main stack
        // If the minStack is empty or the new value is less than or equal to the current minimum
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val); // Push onto the min stack
        }
    }
    
    // Remove the top value from the stack
    void pop() {
        if (mainStack.top() == minStack.top()) {
            minStack.pop(); // Remove from min stack if it's the current minimum
        }
        mainStack.pop(); // Always pop from the main stack
    }
    
    // Get the top value from the stack
    int top() {
        return mainStack.top(); // Return the top element from the main stack
    }
    
    // Get the minimum value from the stack
    int getMin() {
        return minStack.top(); // Return the top of minStack, which is the minimum
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
