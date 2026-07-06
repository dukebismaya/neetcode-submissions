class Solution {
   public:
    int characterReplacement(string s, int k) {
        int max_length{};
        int max_freq{};
        int left = 0;
        std::unordered_map<char, int> freq_map;
        for (int right = 0; right < s.length(); ++right) {
            freq_map[s[right]]++;
            max_freq = std::max(max_freq, freq_map[s[right]]);
            while ((right - left + 1) - max_freq > k) {
                freq_map[s[left]]--;
                left++;
            }
            max_length = std::max(max_length, right - left + 1);
        }
        return max_length;
    }
};
