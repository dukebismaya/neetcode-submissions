class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        std::unordered_set<char> charSet;
        int left{}, max_substr_length{};
        for (int right = 0; right < s.length(); ++right) {
            while (charSet.count(s[right])) {
                charSet.erase(s[left]);
                left++;
            }
            charSet.insert(s[right]);
            max_substr_length = std::max(max_substr_length, right - left + 1);
        }
        return max_substr_length;
    }
};