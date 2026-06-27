class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> freq_map;
        for (const auto &str: strs){
            std::string count_chars(26, ' ');
            for (const char &c: str){
                count_chars[c - 'a']++;
            }
            freq_map[count_chars].push_back(str);
        }
        std::vector<std::vector<std::string>>result;
        for (auto &v: freq_map){
            result.push_back(std::move(v.second));
        }
        return result;
    }
};
