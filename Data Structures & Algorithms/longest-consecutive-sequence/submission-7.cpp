class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max_streak{};
        std::unordered_set<int>num_set(nums.begin(), nums.end());
        for (int num: num_set){
            if (!num_set.count(num-1)){
                int curr_streak {1};
                int curr_num {num};
                while (num_set.count(curr_num+1)){
                    ++curr_streak;
                    ++curr_num;
                }
                max_streak = std::max(max_streak, curr_streak);
            }
        }
        return max_streak;
    }
};
