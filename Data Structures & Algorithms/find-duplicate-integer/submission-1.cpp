class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow {}, fast{};
        while (true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow==fast)
                break;
        }

        int slow2 {};
        while (true){
            slow = nums[slow];
            slow2 = nums[slow2];
            if (slow==slow2)
                return slow;
        }
    }
};
