class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> store_index;
        for (size_t i = 0; i < nums.size(); ++i) {
            int complement = target - nums.at(i);
            auto it = store_index.find(complement);
            if (it != store_index.end()) {
                return {it->second, static_cast<int>(i)};
            }
            store_index[nums.at(i)] = i;
        }

        return {0, 0};

    }
};
