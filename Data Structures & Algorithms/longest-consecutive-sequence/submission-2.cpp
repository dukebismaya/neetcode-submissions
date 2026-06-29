class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest_streak{};
        std::unordered_map<int, int>num_map;
        for (const auto num: nums){
            if (!num_map[num]){
                num_map[num] = num_map[num-1] + num_map[num+1] + 1;
                num_map[num - num_map[num-1]] = num_map[num];
                num_map[num + num_map[num+1]] = num_map[num];
                longest_streak = max(num_map[num], longest_streak);
            }
        }
        return longest_streak;
    }
};
