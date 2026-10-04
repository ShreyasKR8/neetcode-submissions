class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operands;

        for (const string& c : tokens) {
            if (c == "+") {
                int a = operands.top(); 
                operands.pop();
                int b = operands.top(); 
                operands.pop();

                operands.push(b + a);
            } else if (c == "-") {
                int a = operands.top(); 
                operands.pop();
                int b = operands.top(); 
                operands.pop();

                operands.push(b - a);
            } else if (c == "*") {
                int a = operands.top(); 
                operands.pop();
                int b = operands.top(); 
                operands.pop();

                operands.push(b * a);
            } else if (c == "/") {
                int a = operands.top(); 
                operands.pop();
                int b = operands.top(); 
                operands.pop();
                
                operands.push(b / a);
            } else {
                operands.push(stoi(c));
            }
        }
        return operands.top();
    }
};