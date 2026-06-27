class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::unordered_map<std::string, std::vector<std::string>> freq_map;
        freq_map.reserve(strs.size());
        for (const auto& str : strs) {
            std::string count_chars(26, char(0));
            for (const char& c : str) {
                count_chars[c - 'a']++;
            }
            freq_map[count_chars].push_back(str);
        }
        std::vector<std::vector<std::string>> result;
        result.reserve(freq_map.size());
        for (auto& v : freq_map) {
            result.push_back(std::move(v.second));
        }
        return result;
    }
};
