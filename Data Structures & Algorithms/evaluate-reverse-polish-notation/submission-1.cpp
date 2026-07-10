class Solution {
   public:
    auto operation(int op1, int op2, char operator_symbol) -> int {
        switch (operator_symbol) {
            case '+':
                return op1 + op2;
            case '-':
                return op1 - op2;
            case '*':
                return op1 * op2;
            case '/':
                return op1 / op2;
            default:
                return 0;
        }
    }
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> stk;
        static const std::unordered_set<std::string> operators{"+", "-", "*", "/"};
        for (size_t i = 0; i < tokens.size(); ++i) {
            auto c = tokens[i];
            if (operators.contains(c)) {
                int op_2 = stk.top();
                stk.pop();
                int op_1 = stk.top();
                stk.pop();
                stk.push(operation(op_1, op_2, c[0]));
            } else {
                stk.push(std::stoi(c));
            }
        }
        return stk.top();
    }
};