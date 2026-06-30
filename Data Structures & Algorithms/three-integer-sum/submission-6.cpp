class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;
        int num_len = nums.size();
        for (int i = 0; i < num_len; ++i) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            std::unordered_set<int> seen;
            for (int j = i + 1; j < num_len; ++j) {
                int complement = -(nums[i] + nums[j]);
                if (seen.count(complement)) {
                    res.push_back({nums[i], nums[j], complement});
                    while (j + 1 < num_len && nums[j] == nums[j + 1]) ++j;
                }
                seen.insert(nums[j]);
            }
        }

        return res;
    }
};
