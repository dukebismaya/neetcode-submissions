class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.empty()) return 0;
        std::unordered_set<int>num_set;
        for (const int num: nums){
            if (num_set.count(num))
                return num;
            num_set.insert(num);
        }
    }
};
