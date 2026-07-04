class MinStack {
    std::vector<std::pair<int, int>> stk;

   public:
    MinStack() = default;

    void push(int val) {
        if (stk.empty()) {
            stk.push_back({val, val});
        } else {
            stk.push_back({val, std::min(val, stk.back().second)});
        }
    }

    void pop() {
        if (!stk.empty()) {
            stk.pop_back();
        }
    }

    int top() { return stk.back().first; }

    int getMin() { return stk.back().second; }
};
