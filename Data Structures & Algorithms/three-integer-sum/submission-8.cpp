class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty()) return res;
        int target{};
        std::sort(nums.begin(), nums.end());
        int num_len = nums.size();
        for (int i = 0; i < num_len - 2; i++) {
            if (nums[i]>0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int complement = target - nums[i];
            int left = i + 1;
            int right = num_len - 1;
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum == complement) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (right > left && nums[right] == nums[right + 1]) right--;
                } else if (sum < complement)
                    left++;
                else
                    right--;
            }
        }
        return res;
    }
};
