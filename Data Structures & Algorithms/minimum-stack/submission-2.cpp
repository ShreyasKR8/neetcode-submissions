class MinStack {
public:
    stack<int> numStack;
    stack<int> minStack;
    
    MinStack() {

    }
    
    void push(int val) {
        numStack.push(val);
        int min = std::min(val, minStack.empty() ? val : minStack.top());
        minStack.push(min);
    }
    
    void pop() {
        numStack.pop();
        minStack.pop();
    }
    
    int top() {
        return numStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
