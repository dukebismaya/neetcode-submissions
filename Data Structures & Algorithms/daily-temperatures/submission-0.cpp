class Solution {
   public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        std::vector<int> res;
        res.reserve(temperatures.size());
        for (size_t i = 0; i < temperatures.size(); ++i) {
            bool flag = false;
            for (size_t j = i + 1; j < temperatures.size(); ++j) {
                if (temperatures[i] < temperatures[j]) {
                    res.push_back(j - i);
                    flag = true;
                    break;
                }
            }
            if (!flag) res.push_back(0);
        }
        return res;
    }
};
