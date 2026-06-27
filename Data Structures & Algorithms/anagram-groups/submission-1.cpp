class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      std::unordered_map<std::string, std::vector<std::string>> sort_map;
        for (size_t i = 0; i < strs.size(); ++i) {
            std::string temp{strs.at(i)};
            std::sort(temp.begin(), temp.end());
            sort_map[temp].push_back(strs.at(i));
            }
        std::vector<std::vector<std::string>> result_map;
        std::transform(sort_map.begin(), sort_map.end(),
                    std::back_inserter(result_map),
                    [](const auto v) { return v.second; });
        return result_map;  
    }
};
