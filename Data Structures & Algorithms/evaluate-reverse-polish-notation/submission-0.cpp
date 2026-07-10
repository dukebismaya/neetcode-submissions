class Solution {
   public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> stk;
        for (size_t i = 0; i < tokens.size(); ++i) {
            auto c = tokens[i];
            if (c == "+") {
                int op_2 = stk.top();
                stk.pop();
                int op_1 = stk.top();
                stk.pop();
                stk.push(op_1 + op_2);
            } else if (c == "-") {
                int op_2 = stk.top();
                stk.pop();
                int op_1 = stk.top();
                stk.pop();
                stk.push(op_1 - op_2);
            } else if (c == "/") {
                int op_2 = stk.top();
                stk.pop();
                int op_1 = stk.top();
                stk.pop();
                stk.push(op_1 / op_2);
            } else if (c == "*") {
                int op_2 = stk.top();
                stk.pop();
                int op_1 = stk.top();
                stk.pop();
                stk.push(op_1 * op_2);
            } else {
                stk.push(std::stoi(c));
            }
        }
        return stk.top();
    }
};
