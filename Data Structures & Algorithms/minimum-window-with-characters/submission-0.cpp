class Solution {
   public:
    string minWindow(string s, string t) {
        std::unordered_map<char, int> countT;
        for (const auto& c : t) {
            countT[c]++;
        }
        int res_len = INT_MAX;
        int result_start_idx = -1;
        for (size_t i = 0; i < s.length(); ++i) {
            std::unordered_map<char, int> countS;
            for (size_t j = i; j < s.length(); ++j) {
                countS[s[j]]++;
                bool flag = true;
                for (const auto& [key, val] : countT) {
                    if (countS[key] < val) {
                        flag = false;
                        break;
                    }
                }
                if (flag && j - i + 1 < res_len) {
                    res_len = j - i + 1;
                    result_start_idx = i;
                }
            }
        }
        return res_len == INT_MAX ? "" : s.substr(result_start_idx, res_len);
    }
};
