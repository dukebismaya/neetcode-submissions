class Solution {
public:
    std::unordered_map<int, int>num_map;
    int find_end(int x){
        if (num_map.find(x)==num_map.end()) return x;
        return num_map[x] = find_end(num_map[x]);
    }
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        for (const auto num: nums){
            num_map[num] = num+1;
        }
        int longest_chain {};
        for (const auto &[num, _]: num_map){
            int curr_chain_length = find_end(num) - num;
            longest_chain = std::max(curr_chain_length, longest_chain);
        }
        return longest_chain;
    }
};
