class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::vector<std::pair<int, int>> pos_speed;
        for (size_t i = 0; i < position.size(); ++i) {
            pos_speed.push_back(std::make_pair(position[i], speed[i]));
        }
        std::sort(pos_speed.begin(), pos_speed.end(),
                  [](const auto car1, const auto car2) { return car1.first > car2.first; });
        std::stack<double> stk;
        for (const auto& p : pos_speed) {
            auto curr_time = static_cast<double>(target - p.first) / p.second;

            if (stk.empty() || curr_time > stk.top()) {
                stk.push(curr_time);
            }
        }
        return stk.size();
    }
};