class Solution {
   public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        std::vector<int> res(temperatures.size(), 0);
        std::stack<int> stk;
        for (size_t i = 0; i < temperatures.size(); ++i) {
            while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
                int prev_idx = stk.top();
                stk.pop();
                res[prev_idx] = i - prev_idx;
            }
            stk.push(i);
        }
        return res;
    }
};
