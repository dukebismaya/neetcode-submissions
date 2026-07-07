class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        std::vector<int> s1_count(26, 0);
        std::vector<int> window_count(26, 0);
        for (size_t i = 0; i < s1.length(); ++i) {
            s1_count[s1[i] - 'a']++;
            window_count[s2[i] - 'a']++;
        }
        for (size_t i = 0; i + s1.length() < s2.length(); ++i) {
            if (s1_count == window_count) return true;
            window_count[s2[i + s1.length()] - 'a']++;
            window_count[s2[i] - 'a']--;
        }
        return s1_count == window_count;
    }
};
