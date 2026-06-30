class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left{};
        int right = numbers.size() - 1;
        while (left < right) {
            int get_sum = numbers[left] + numbers[right];
            if (get_sum == target)
                return {left + 1, right + 1};
            else if (get_sum < target) {
                int needed = target - numbers[right];
                auto it =
                    std::lower_bound(numbers.begin() + left + 1, numbers.begin() + right, needed);
                left = std::distance(numbers.begin(), it);
            } else {
                int needed = target - numbers[left];
                auto it =
                    std::upper_bound(numbers.begin() + left + 1, numbers.begin() + right, needed);
                right = std::distance(numbers.begin(), it) - 1;
            }
        }
        return {};
    }
};
