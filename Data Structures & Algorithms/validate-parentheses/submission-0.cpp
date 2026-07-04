class Solution {
   public:
    bool isValid(string s) {
        stack<char> curr_stack;
        unordered_map<char, char> alter_brace{{'}', '{'}, {')', '('}, {']', '['}};
        for (size_t i = 0; i < s.length(); ++i) {
            char c = s[i];
            if (c == '(' || c == '[' || c == '{') {
                curr_stack.push(c);
                continue;
            }
            if (curr_stack.empty() || alter_brace[c] != curr_stack.top()) {
                return false;
            }
            curr_stack.pop();
        }
        return curr_stack.empty();
    }
};
