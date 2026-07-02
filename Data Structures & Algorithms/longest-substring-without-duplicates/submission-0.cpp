class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        std::string longest_unique{s[0]};
        size_t max_len = 1;
        size_t i = 1;
        while (i < s.size()) {
            auto pos = longest_unique.find(s[i]);
            if (pos==string::npos){
                longest_unique += s[i];
            } else {
                max_len = max(longest_unique.length(), max_len);
                longest_unique = longest_unique.substr(pos+1) + s[i];
            }
            i++;
        }
        return max(max_len, longest_unique.length());
    }
};
