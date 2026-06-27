class Solution {
   public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::unordered_map<int, int> freq_map;
        for (const auto num : nums) {
            freq_map[num]++;
        }
        std::vector<std::pair<int, int>> sorted_freq_map{freq_map.begin(), freq_map.end()};
        std::sort(sorted_freq_map.begin(), sorted_freq_map.end(),
                  [](const auto& x, const auto& y) { return x.second > y.second; });
        std::vector<int> result;
        for (size_t i = 0; i < k; i++) {
            result.push_back(sorted_freq_map.at(i).first);
        }
        return result;
    }
};