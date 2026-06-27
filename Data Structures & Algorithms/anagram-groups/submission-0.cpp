class Solution {
public:
  bool is_anagram(std::string const &str1, std::string const &str2) {
    if (str1.length() != str2.length())
      return false;
    std::unordered_map<char, int> str1_map;
    std::unordered_map<char, int> str2_map;
    for (const auto &c : str1) {
      str1_map[c]++;
    }
    for (const auto &c : str2) {
      str2_map[c]++;
    }
    return str1_map == str2_map;
  }
  std::vector<std::vector<std::string>>
  groupAnagrams(std::vector<std::string> &strs) {
    std::vector<std::vector<std::string>> result_arr;
    for (size_t i = 0; i < strs.size(); ++i) {
      bool found_group = false;
      for (size_t j = 0; j < result_arr.size(); ++j) {
        if (is_anagram(result_arr.at(j).at(0), strs.at(i))) {
          result_arr[j].push_back(strs.at(i));
          found_group = true;
        }
      }
      if (!found_group)
        result_arr.push_back({strs.at(i)});
    }
    return result_arr;
  }
};
