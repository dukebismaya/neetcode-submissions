class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> sort_map;
        for (const auto &str : strs) {
            std::string temp{str};
            std::sort(temp.begin(), temp.end());
            sort_map[temp].push_back(str);
        }
        std::vector<std::vector<std::string>> result_map;
        result_map.reserve(sort_map.size());
        std::transform(sort_map.begin(), sort_map.end(),
                    std::back_inserter(result_map),
                    [](auto &v) { return std::move(v.second); });
        return result_map;
    }
};
