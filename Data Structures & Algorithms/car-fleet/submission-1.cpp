class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::vector<std::pair<int, int>> pos_speed;
        pos_speed.reserve(position.size());
        for (size_t i = 0; i < position.size(); ++i) {
            pos_speed.push_back({position[i], speed[i]});
        }

        std::sort(pos_speed.rbegin(), pos_speed.rend());

        int fleets = 0;
        double max_time = -1.0;
        for (const auto& p : pos_speed) {
            double curr_time = static_cast<double>(target - p.first) / p.second;
            if (curr_time > max_time) {
                fleets++;
                max_time = curr_time;
            }
        }
        return fleets;
    }
};
