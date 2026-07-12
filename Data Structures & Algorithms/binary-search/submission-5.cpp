class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (target < nums[mid])
                right = mid;
            else
                left = mid + 1;
        }
        return (left > 0 && nums[left - 1] == target) ? left - 1 : -1;
    }
};
