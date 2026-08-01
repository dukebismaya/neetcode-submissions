class Solution {
   public:
    bool isPalindrome(string s) {
        std::string base_str{};
        for (const auto c : s) {
            if (!std::isalnum(c)) continue;
            base_str += static_cast<char>(std::tolower(c));
        }
        int n = base_str.length();
        for (int i = n - 1; i >= 0; --i) {
            if (base_str[i] != base_str[n - i - 1]) return false;
        }
        return true;
    }
};