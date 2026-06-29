class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest_streak{};
        std::unordered_set<int>num_set(nums.begin(), nums.end());
        for (const auto num: nums){
            if (num_set.find(num-1)==num_set.end()){
                int curr_streak = 1;
                while (num_set.find(num+curr_streak)!=num_set.end()){
                    curr_streak++;
                }
                longest_streak = std::max(curr_streak, longest_streak);
            }
        }
        return longest_streak;
    }
};
