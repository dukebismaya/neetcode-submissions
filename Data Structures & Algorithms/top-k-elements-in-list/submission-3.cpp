class Solution {
   public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::unordered_map<int, int> freq_map;
        for (const auto num : nums) {
            freq_map[num]++;
        }
        std::vector<std::vector<int>> sorted_freq_map(nums.size() + 1);
        for (const auto& [num, freq] : freq_map) {
            sorted_freq_map[freq].push_back(num);
        }
        std::vector<int> result;
        for (int i = sorted_freq_map.size() - 1; i >= 0 && result.size() <= k; --i) {
            for (int num : sorted_freq_map.at(i)) {
                result.push_back(num);
                if (result.size() == k) return result;
            }
        }
        return result;
    }
};