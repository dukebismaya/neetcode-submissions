class Solution {
   public:
    bool isPalindrome(string s) {
        int l_idx = 0;
        int r_idx = s.size() - 1;
        while (l_idx < r_idx) {
            while (l_idx < r_idx && !std::isalnum(s[l_idx])) l_idx++;
            while (r_idx > l_idx && !std::isalnum(s[r_idx])) r_idx--;
            if (std::tolower(s[l_idx]) != std::tolower(s[r_idx])) return false;
            l_idx++;
            r_idx--;
        }
        return true;
    }
};
