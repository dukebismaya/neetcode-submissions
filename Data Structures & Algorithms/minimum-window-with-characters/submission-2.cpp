class Solution {
   public:
    string minWindow(string s, string t) {
        std::unordered_map<char, int> countT, window_count;
        for (const auto& c : t) {
            countT[c]++;
        }
        size_t left = 0;
        int curr_count = 0, needed = countT.size();
        int start_substr_pos = 0;
        int res_len = INT_MAX;
        for (size_t right = 0; right < s.length(); ++right) {
            char c = s[right];
            window_count[c]++;
            if (countT.count(c) && window_count[c] == countT[c]) {
                curr_count++;
            }
            while (curr_count == needed) {
                if (res_len > right - left + 1) {
                    res_len = right - left + 1;
                    start_substr_pos = left;
                }
                window_count[s[left]]--;
                if (countT.count(s[left]) && window_count[s[left]] < countT[s[left]]) {
                    curr_count--;
                }
                left++;
            }
        }
        return res_len == INT_MAX ? "" : s.substr(start_substr_pos, res_len);
    }
};
