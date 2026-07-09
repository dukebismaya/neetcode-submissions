class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<int> result(n - k + 1);
        std::deque<int> query;
        int left = 0, right = 0;
        while (right < n) {
            while (!query.empty() && nums[query.back()] < nums[right]) {
                query.pop_back();
            }
            query.push_back(right);

            if (left > query.front()) query.pop_front();

            if (right + 1 >= k) {
                result[left] = nums[query.front()];
                left++;
            }
            right++;
        }
        return result;
    }
};
