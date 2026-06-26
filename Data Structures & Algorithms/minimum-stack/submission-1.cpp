class MinStack {
public:
    stack<int> minStack;
    stack<int> minNumStack;
    int minNum;
    
    MinStack() {

    }
    
    void push(int val) {
        minStack.push(val);
        if(minNumStack.empty() || minNumStack.top() >= val) {
            minNumStack.push(val);
        }
    }
    
    void pop() {
        if(minStack.top() == minNumStack.top()){
            minNumStack.pop();
        }
        minStack.pop();
    }
    
    int top() {
        return minStack.top();
    }
    
    int getMin() {
        return minNumStack.top();
    }
};
