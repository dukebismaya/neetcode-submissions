class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        std::unordered_map<int, int>num_idx_map;
        for (size_t i=0; i<numbers.size(); ++i){
            int complement = target-numbers.at(i);
            if (num_idx_map.find(complement)!=num_idx_map.end())
                return {num_idx_map[complement]+1, static_cast<int>(i)+1};
            
            num_idx_map[numbers.at(i)] = static_cast<int>(i);
        }
    }
};
